/*
 * @Descripttion: 
 * @version: 
 * @Author: colley
 * @Date: 2020-02-29 01:14:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-29 01:34:28
 */
#include <iostream>     /**< std::cout */

class Account
{
public:
    Account(const std::string &name, double deospit)
        : m_name(name)
        , m_deospit(deospit){}
    ~Account(){};
    static double showIntersting()
    {
        return m_intersting;
    }
private:
    std::string m_name;
    double m_deospit;
    static double m_intersting;
    //error: static double m_intersting = 0; //不能再内部赋值
    //ok: const / static const 都必须内部赋值
};
double Account::m_intersting = 0.04;

int main(int argc, char** argv)
{
    std::cout << "main function begin!!" << std::endl;
    Account account("colley",14);
    Account account1("li", 17);
    ///static 特点（1）赋值（2）一个类中的static无论创建多少个类，static的成员变量都一样。（3）static初始化在main之前
    std::cout << "account intersting: " << account.showIntersting() << std::endl;
    std::cout << "account1 intersting: " << account1.showIntersting() << std::endl;
    std::cout << "main function end!!!" << std::endl;
    return 0;
}