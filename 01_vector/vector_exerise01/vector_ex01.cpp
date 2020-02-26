/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-22 15:32:18
 */

#include <iostream> /**< std::cout std::endl */
#include <vector>   /**< std::vector */

int main(void) {
    std::vector<int> vec1;
    int iVal;
    std::cout << "Enter number(Ctrl+z to end)" << std::endl;
    while(std::cin >> iVal)
        vec1.push_back(iVal);

    if(vec1.empty())
    {
        std::cout << "vec1 No element!" << std::endl;
        return -1;
    }
    ///demo1
    for(std::vector<int>::size_type idex = 0; idex < vec1.size()-1; idex = idex + 2)
    {
        std::cout << vec1[idex] + vec1[idex+1] << std::endl;
    }
    if(vec1.size() % 2 != 0)
    {
        std::cout << "the last number: ";
        std::cout << vec1[vec1.size()-1] << std::endl;
    }

    ///demo2
    std::vector<int>::size_type first,last;
    for (first = 0, last = vec1.size()-1; first < last; ++first,--last)
    {
        std::cout << vec1[first] + vec1[last] << std::endl;
    }
    return 0;
}