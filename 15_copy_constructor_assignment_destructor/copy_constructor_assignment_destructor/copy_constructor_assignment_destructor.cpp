/*
 * @Descripttion: 
 * @version: 
 * @Author: colley
 * @Date: 2020-02-29 01:14:34
 * @LastEditors: colley
 * @LastEditTime: 2020-03-02 00:23:08
 */
#include <iostream>     /**< std::cout */

class Account
{
public:
    Account() : m_name("defalut") , m_deospit(0)
    {
        std::cout << "constructor1" << std::endl;
    }

    Account(const std::string &name, double deospit = 0)
        : m_name(name)
        , m_deospit(deospit)
    {
        std::cout << "constructor2" << std::endl;
    }

    ~Account()
    {
        //std::cout << "destructor" << std::endl;
    };
    // 拷贝构造函数
    Account(const Account &copyConstructor) : m_name(copyConstructor.m_name), m_deospit(copyConstructor.m_deospit)
    {
        std::cout << "Account copy copyConstructor." << std::endl;
    }

    // 拷贝赋值函数C
    Account &operator=(const Account &AssignmentConstructor)
    {
        m_name = AssignmentConstructor.m_name;
        m_deospit = AssignmentConstructor.m_deospit;
        std::cout << "Assigenmet Constructor. " << std::endl;
        return *this;
    }

private:
    std::string m_name;
    double m_deospit;
};

Account AccountFunction(const Account &account) //Account AccountFunction(Account& account)
{
    Account account1;
    account1 = account;
    return account1;
}
// test: begin
// constructor2
// constructor1
// Account copy copyConstructor.
// constructor1
// Assigenmet Constructor.
// Assigenmet Constructor.
// test: end

Account AccountFunction1(Account account)
{
    Account account1;
    account1 = account;
    return account1;
}
// test: begin
// constructor2
// constructor1
// constructor1
// Assigenmet Constructor.
// Assigenmet Constructor.
// test: end

int main(int argc, char** argv)
{
    ///demo1:测试
    Account accout;
    Account accout2("shark");
    Account accout3(accout2); //等同于 Account account3 = accout2;
    Account accout4;
    accout4 = accout3;
    std::cout << std::endl << "test: begin" << std::endl;
    Account accout5 = std::string("1111");
    Account accout6;
    accout6 = AccountFunction1(accout5);
    std::cout << "test: end" << std::endl;
    ///demo2:如果出现指针成员必须要自己写拷贝构造函数和赋值构造函数（因为系统自带的拷贝构造函数和赋值构造函数会将地址拷贝从而出现问题）
    return 0;
}