/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-22 15:13:01
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> /**< std::cout std::endl */
#include <vector>   /**< std::vector */

int main(void) {
    std::vector<int> vec1(10,2);
    std::vector<int> vec2;
    std::cout << "vec2.size(): " << vec2.size() << std::endl;
    std::cout << "vec2.empty(): " << vec2.empty() << std::endl;
    vec2.push_back(2);
    std::cout << "vec2.empty(): " << vec2.empty() << std::endl;
    for(std::vector<int>::size_type i = 0; i != vec1.size(); ++i)
    {
        std::cout << vec1[i] << std::endl;
    }

    return 0;
}