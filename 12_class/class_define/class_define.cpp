/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-27 00:49:09
 */

#include <iostream> /**< std::cout std::endl */
#include <string>   /**< std::string std::string::size_type */
#include <vector>   /**< std::vector */
class Book
{
public:
    Book(const std::string &name, const std::string &price)
            : m_name(name)
            , m_price(price){}
    ~Book(){}
    std::string getName() const //如果不加const, sameBook中book.getName()会出现问题
    {
        return m_name;
    }

    bool sameBook(const Book &book) const
    {
        if(m_name == book.getName())
        {
            return true;
        }
        return false;
    }
private:
    std::string m_name;
    std::string m_price;
};

class Person
{
public:
    Person(const std::string &name, const std::string &address)
                        : m_name(name)
                        , m_address(address){} //参数列表形式比较好
    ~Person(){}
    std::string getName()
    {
        return m_name;
    }

    std::string getAddress()
    {
        return m_address;
    }

private:
    std::string m_name;
    std::string m_address;
};

int main(int arvc, char**argv)
{
    Person colley("li","NavInfo");
    std::cout << "name: " << colley.getName() << std::endl;
    std::cout << "address: " << colley.getAddress() << std::endl;
    Book shark("shark","23.00");
    Book shark1("shark1", "23.00");
    shark1.sameBook(shark1);
    std::cout << "samebook: " << shark1.sameBook(shark1) << std::endl;
    std::cout << "samebook: " << shark1.sameBook(shark) << std::endl;
    return 0;
}