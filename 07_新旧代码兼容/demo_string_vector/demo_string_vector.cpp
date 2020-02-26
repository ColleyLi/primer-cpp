/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-23 21:39:19
 */

#include <iostream> /**< std::cout std::endl */
#include <cstring>  /**< strcpy */
#include <vector>   /**< std::vector */

int main(void) {
   ///demo1: char <------> string 指针和c_str()
    std::string str("hello");
    str = str + "bill";

    const char *cCharPtr = str.c_str();
   ///demo2: array <------> vector
   const size_t num = 9;
   int intArray[num] = {0,8};

   std::vector<int>(intArray, intArray+num);//c/c++ 特点：前包后不包： [  )
    return 0;
}