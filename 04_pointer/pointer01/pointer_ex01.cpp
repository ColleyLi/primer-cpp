/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-23 14:15:23
 */

#include <iostream> /**< std::cout std::endl */
#include <string>   /**< std::string */

typedef std::string *pstring;

int main(void) {
    std::string s("hello world!");
    std::string *sPtr = &s;
    std::cout << "s: " << s << std::endl;
    std::cout << "sPtr: " << *sPtr << std::endl;

    ///demo1: *号的位置
    std::string* ptr, s1; //s1不是指针,容易误解(N)
    std::string *ptr1, *ptr2;//（Y）
    int a = 9;
    void* vPtr = &a;
    int *iPtr = (int*)(vPtr);
    //error:     std::cout << *vPtr << std::endl; void *不能查看内容需要做具体类型转化
    std::cout << *iPtr << std::endl;

    ///demo2: 指针和数组
    int iArr[] = {9,3,4,6};
    int *iPtr1 = iArr;                       ///< iArr是数组的第一个值的指针
    std::cout << iPtr1 << " " << iArr << std::endl;
    int iVal = *iPtr1;                       ///< 解引用
    int iVal2 = *(iArr + 1);                ///< 解引用
    ptrdiff_t ptrDiff = (iArr+1) - iPtr1;    ///< 指针的差
    std::cout << "ptrDiff: " << ptrDiff << std::endl;

    ///demo3: 指向常(const)对象的指针、常（cosnt）指针、指向常(const)对象的常（const）指针
    const double pi = 3.14;
    double mathPi = 3.14;
    //error: double *mathPi = &pi; //常对象不能指向非常（const）指针
    const double * cPiPtr = &pi;    //常对象指针指向常对象指针
    const double * cMathPiPtr = &mathPi;
    const double * cTest;
    //error: double* const testCPtr; //常指针需要初始化
    const double * const cPiCPtr = &pi;// 指向常对象的常指针
    // 讨论const pstring cstr与const std::string *cPtr1; (N)一样还是与std::string* const cPtr2; (Y)

    return 0;
}