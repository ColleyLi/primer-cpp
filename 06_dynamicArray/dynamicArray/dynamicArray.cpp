/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-23 21:27:52
 */

#include <iostream> /**< std::cout std::endl */
#include <cstring>  /**< strcpy */

int main(void) {
    ///demo1: malloc free  / new delete   静态：栈 /动态：堆
    int num = 8;
    int *m = (int*)malloc(num * sizeof(int));
    free(m);
    ///demo2: 开辟指针空间和初始化
    int *p = new int[10];//未初始化
    delete[] p;
    int *p1 = new int[10]();                //开辟空间并初始化,初始化其值为零
    delete[] p1;
    std::string *pStr = new std::string[10];//开辟空间并初始化（std::string是类会调用默认构造函数）
    delete[] pStr;
    ///demo3:
    const int *cPtrI = new const int[10]();//需要初始化，但是没有用
    delete[] cPtrI;
    //error: char arr[0]; //静态不能创建为零的数组
    int *zPtr = new int[0];//动态数组可以创建零数组
    delete[] zPtr;
    ///demo4: char 动态数组和string
    const char * cPtrChar = "test: const char~";
    const std::string cStr = cPtrChar;
    char *cPtrChar1 = "test: const char~";
    std::string cStr1 = cPtrChar;
    std::cout << "cStr1: " << cStr1 << std::endl;
    std::cout << "cStr: " << cStr.length() << std::endl;
    std::cout << "cPtrChar[0]: " << *cPtrChar << std::endl;
    std::cout << "cPtrChar: " << cPtrChar << std::endl;
    const size_t len = strlen(cPtrChar);
    for(size_t i = 0; i !=5; ++i)
    {
        char *cPtr = new char[len+1];
        strcpy(cPtr,cPtrChar);
        std::cout << cPtr << std::endl;
    }
    return 0;
}