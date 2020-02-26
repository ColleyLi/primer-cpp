/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-23 17:17:28
 */

#include <iostream> /**< std::cout std::endl */
#include <cstring>  /**< std::string strcpy() strcat() */

int main(void) {
    std::string str("hello");
    char cp1[] = "hello";
    char cp2[] = "world";
    char cp3[] = "test";
    char c1[] = {'c','+','+'};

    std::string s1("hello");
    std::string s2("world");
    std::string s3("!");

    ///demo1: char指针问题
    char *cPtr = c1;
    char *cPtr1 = cp1;
    std::cout << "cPtr: " << *cPtr << std::endl;
    std::cout << "cPtr1: " << *cPtr1 << std::endl;

    const char * cChar = "hello!";
    std::cout << "test" << std::endl;
    while(*cChar) // end '\0' 转化成0
    {
        std::cout << *cChar << std::endl;
        ++cChar;
    }

    ///demo1: '/0' strlen()不存在'\0'问题(.size()/.length()函数就没有问题)
    std::cout << "strlen(cp1): " << strlen(cp1) << std::endl;
    std::cout << "string length: " << s1.length() << std::endl;
    ///demo3: C风格strcmp:比较大小 0，1，-1  C++:string则可以直接比较大小
    std::cout << "strcmp: " << strcmp(cp1,cp2) << std::endl;
    std::cout << "string compare: " << (s1 < s2) << std::endl; //type: bool

    ///demo4: char赋值c1 = c2; copy: strcpy(c1,c2)  string: copy: s1 = s2;
    ///demo5: 连接：c1,c2 （1）strcpy() strcat()    string: stringS = s1+s2
    char largeChar[30];      ///< 缺点需要设置比较大的size如果较小会导致strcat()出现问题
    strcpy(largeChar,cp1);
    strcat(largeChar,cp2);
    std::cout << "largeChar: " << largeChar << std::endl;
    strncpy(largeChar, cp3, 2); ///< strncpy() strncat()
    strncat(largeChar, cp2, 2);
    std::cout << "largeChar: " << largeChar << std::endl;

    s3 = s2;
    std::cout << "s3: " << s3 << std::endl;
    s3 = s1 + s2;
    std::cout << "s3: " << s3 << std::endl;
    return 0;
}