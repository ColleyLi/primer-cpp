/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-22 17:11:38
 */

#include <iostream> /**< std::cout std::endl */
#include <vector>   /**< std::vector */
#include <string>   /**< std::string */

using namespace std;

int main(void) {
    vector<string> vecStr;
    string str;
    while(cin >> str)
        vecStr.push_back(str);

    if(vecStr.empty())
    {
        cout << "vecStr is empty." << endl;
        return -1;
    }
    for(vector<string>::size_type index = 0; index < vecStr.size(); ++index)
    {
        for(vector<string>::size_type subIndex = 0; subIndex < vecStr[index].size(); ++subIndex)
        {
            if(islower(vecStr[index][subIndex]))
            {
                vecStr[index][subIndex] = toupper(vecStr[index][subIndex]);
            }
        }
        cout << vecStr[index] << " ";
        if (index % 8 == 0)
        {
            cout << endl;
        }
    }
    return 0;
}