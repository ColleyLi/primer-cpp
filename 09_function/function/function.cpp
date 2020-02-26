/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-25 16:33:45
 */

#include <iostream> /**< std::cout std::endl */
#include <string>   /**< std::string std::string::size_type */
#include <vector>   /**< std::vector */

template<typename T>
T abs(T value)
{
    return value > 0? value:-value;
}

void addOne(int value)
{
    value = value + 1;
}

//error: const int 和int 程序认为是一样的不算是重载
// void addOne(const int value)
// {

// }

void addOne(double value)
{
    value = value + 1;
}


void addOneReferece(int &value)
{
    value = value + 1;
}

void addOnePtr(int* ptr)
{
    *ptr = *ptr + 1;
}

std::string::size_type find_char(std::string& s,char c)
{
    std::string::size_type i = 0;
    while(i != s.size() && s[i] != c)
        ++i;
    return i;
}

std::string::size_type find_char_c(const std::string &s, char c)
{
    std::string::size_type i = 0;
    while (i != s.size() && s[i] != c)
        ++i;
    return i;
}

void ptrSwap(int* &ptr1, int *&ptr2)
{
    int*tmp = ptr2;
    ptr2 = ptr1;
    ptr1 = tmp;
}

void printVector(std::vector<double>::const_iterator begin,
                 std::vector<double>::const_iterator end)
{
    while(begin!=end)
    {
        std::cout << *begin++ << std::endl;
    }
}
//二维的数组
void printValues(int (*x)[3], int rowSize)
{
    for(int i = 0; i!=rowSize; ++i)
    {
        for(int j=0; j!=3; ++j)
        {
            std::cout << x[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    ///demo1:
    double value = -1;
    double absValue = abs(value);
    std::cout << "absValue: " << absValue << std::endl;
    ///demo2: 非引用形参（const/非const普通形参,const/非const指针）
    //实质：copy
    int a = 1;
    std::cout << "before a: " << a << std::endl;
    addOne(a);
    std::cout << "after a: " << a << std::endl;
    addOneReferece(a);
    std::cout << "after2 a: " << a << std::endl;
    //非const指针copy的还是指针所以会改变结果
    int *iPtr = &a;
    addOnePtr(iPtr);
    std::cout << "after3 a: " << a << std::endl;
    const int cValue = 4;
    // addOne(cValue);
    // std::cout << "cValue: " << cValue << std::endl;
    ///缺点：大数据进行copy很慢
    class Dog
    {
        int a[10000];
    };
    ///demo3:引用形参
    //对实参数修改
    //非const引用不能用右值初始化
    //error: std::string::size_type num = find_char("hello!",'o');
    std::string::size_type num = find_char_c("hello!", 'o');
    ///demo4: 指针的引用：交换的是指针
    int i = 10;
    int j = 20;
    int *iPtr1 = &i;
    int *jPtr2 = &j;
    std::cout << "i: " << i << "j: " << j << std::endl;
    std::cout << "before：" << *iPtr1 << " " << *jPtr2 << std::endl;
    std::cout << "before：" << iPtr1 << " " << jPtr2 << std::endl;
    ptrSwap(iPtr1,jPtr2);
    std::cout << "i: " << i << "j: " << j << std::endl;
    std::cout << "after: " << *iPtr1 << " " << *jPtr2 << std::endl;
    std::cout << "after: " << iPtr1 << " " << jPtr2 << std::endl;
    ///demo5: 容器vector传参(1)：非引用--->不建议(2):引用--->一般(3):更喜欢传递迭代器
    std::vector<double> dVec;
    dVec.push_back(1.1);
    dVec.push_back(2.2);
    dVec.push_back(3.3);
    printVector(dVec.begin(),dVec.end());
    ///demo6: 向函数传递数组
    //三种形参： （int*x,size_t size）; (int x[], size_t size); (int x[10],size_t size);三种写法一样其中10没有什么用，最好用指针前面可以加const
    //引用的方法：（int(&x)[10]）这里面10必须写，(int &x[10] ,size_t size)可以不写
    int arr[] = {0,1,2,3,4};
    int arr2[][3] = {{3},{4},{5},{6,1,3}};
    printValues(arr2, 4);
    return 0;
}