/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-26 22:44:59
 */

#include <iostream> /**< std::cout std::endl */
#include <string>   /**< std::string std::string::size_type */
#include <vector>   /**< std::vector */

int main(int arvc, char**argv) //(int argc,char* argv[])
{
    if(arvc < 3)
    {
        std::cout << "Number of parameters less than 3" << std::endl;
        return 0;
    }
    std::cout << "0: " << argv[0] << std::endl;
    std::cout << "1: " << argv[1] << std::endl;
    std::cout << "2: " << argv[2] << std::endl;
    int k = 0;
    for (auto i = 1; i < arvc; ++i)
    {
        k = k + atoi(argv[i]);
        std::cout << "k: " << k << std::endl;
    }
    return 0;
}