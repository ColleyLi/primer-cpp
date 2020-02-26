/*
 * @Descripttion:
 * @version:
 * @Author: colley
 * @Date: 2020-02-21 22:29:34
 * @LastEditors: colley
 * @LastEditTime: 2020-02-22 21:00:56
 */

#include <iostream> /**< std::cout std::endl */
#include <bitset>   /**< std::bitset */
#include <string>   /**< std::string */

int main(void) {
    ///demo1
    std::bitset<32> a(0xffff);
    std::cout << a << std::endl;
    ///demo2
    std::string str("010101111000011001101");
    std::bitset<32> f(str, 5, 4); //从正方向第五位开始数result:00000000000000000000000000001111(01010----1111----000011001101)
    std::cout << f << std::endl;
    ///demo3 type:bool 1.any()是否存在1 2.none()是否全为零 3.count()1的个数 4.size()0和1总的个数
    ///demo4: 位的操作
    std::bitset<32> b;
    b[1] = 1;
    std::cout << "b: " << b << std::endl;
    ///demo5: set(index):将index位变为1 reset():变为零
    b.set(8);
    std::cout << "b: " << b << std::endl;
    ///demo6: flip()反转
    ///demo7: 转化成十进制数：
    unsigned long c = b.to_ulong();
    std::cout << "十进制b: " << c << std::endl;
    ///demo8: 位的与、或、异或
    std::bitset<8> eightBits1(24);
    std::bitset<8> eightBits2(108);
    std::cout << eightBits1 << std::endl;
    std::cout << eightBits2 << std::endl;
    std::cout << (eightBits1 & eightBits2) << std::endl;
    std::cout << (eightBits1 | eightBits2) << std::endl;
    std::cout << (eightBits1 ^ eightBits2) << std::endl;
    ///缺点：位数初始化就固定了
    return 0;
}