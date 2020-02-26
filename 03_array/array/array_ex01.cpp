/*
 * @Descripttion:
 * 1、缺点数组大小固定
 * 2、长度不能知道要通过变量记住
 * 3、不支持push_back...
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-22 21:37:37
 */

#include <iostream> /**< std::cout std::endl */
#include <string>   /**< std::string */

const int getSize()
{
    return (2 + 3);
}

int main(void) {
    int a[100];
    ///demo1: 初始化要是一个常量不能是变量/函数返回值（编译时不能确定大小）
    const unsigned bufSize = 512, maxFile = 20;
    int staffSize = 27;
    int b[bufSize];
    // error: int c[staffSize];
    // error: int d[getSize()];
    // error: int f[3] = {1,3,5,7}; 数组不能越界，
    int e[] = {12,90,4};

    ///demo2: size_t array专用的下表类型
    const size_t arraySize = 5;
    int arr1[arraySize] = {2,34,5};
    ///demo3: 引用下标越界会出现用到乱的数据（缓冲区溢出）
    for(size_t i = 0; i < arraySize+5; ++i)
    {
        std::cout << "arr1[" << i << "]: " << arr1[i] << std::endl;
    }
    ///demo4: arrC2 和arrC3没有区别都是字符串 arrC1是字符数组
    char arrC1[] = {'a','b'};
    char arrC2[] = {'a', 'b','\0'};
    char arrC3[] = "ab";
    //error: arrC4[2] = "ab"; 大小不够忘记'\0'，存储空间可以大但是不能小类似:int f[3] = {1,3,5,7};
    return 0;
}