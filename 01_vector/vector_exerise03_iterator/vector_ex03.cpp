/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-22 17:53:34
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
    /// demo1: index
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
        if (index!=0 && index % 8 == 0)
        {
            cout << endl;
        }
    }
    ///demo2: iterator && const_iterator
    cout << "iterator demo" << endl;
    for(vector<string>::iterator iter = vecStr.begin(); iter != vecStr.end(); ++iter)
    {
        cout << "vecStr: " << *iter << endl;
    }
    ///demo3: auto
    for (auto iter = vecStr.begin(); iter != vecStr.end(); ++iter)
    {
        cout << "tolower vecStr: " << (*iter) << endl;
        cout << "length: " << (*iter).length() << std::endl;
        cout << "size: " << (*iter).size() << std::endl;
    }
        return 0;
}