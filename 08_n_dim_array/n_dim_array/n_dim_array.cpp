/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-25 13:03:52
 */

#include <iostream> /**< std::cout std::endl */
#include <cstring>  /**< strcpy */
#include <vector>   /**< std::vector */

int main(void) {
    const size_t rowSize = 3;
    const size_t colsSize = 4;

    int iArray[rowSize][colsSize] = {{0},{1,2,3}};
    int(*ptr)[4];// ptr是指针，可以用typedef区分typedef iPtr *int
    int *ptr1[4];// ptr1是数组：里面有四个指针元素
}