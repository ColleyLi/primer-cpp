<!--
 * @Description:
 * @version:
 * @Author: colley
 * @Date: 2020-03-14 11:58:11
 * @LastEditors: colley
 * @LastEditTime: 2020-03-15 18:23:14
 -->
## C++ 函数重载

- 规则
    - 函数名相同
    - 参数的个数不同、参数的类型不同、参数顺序不同（满足其一即可）
- 注意
    - 返回值类型与函数重载没有关系
    - 调用函数时，实参的隐式类型转换可能会产生二义性
- 本质
    - 采用`name mangling`或者叫`name decoration`技术

!!! NOTE

- C++编译器会默认对符号名（函数名）进行改编、修饰，有些地方翻译为"命名倾轧"
- C语言不可以实现函数重载


## Demo以及汇编查看如何实现

```c++
#include <iostream>

void function()
{
	std::cout << "fuction()" << std::endl;
};

void function(double inputValue)
{
	std::cout << "function(double a)" << inputValue <<std::endl;
}

void function(float inputValue)
{
	std::cout << "function(float a)" << inputValue << std::endl;
}

int main(int argc, char** argv)
{
    function();
	function(10.0);
	function(10.0f);
	return 0;
}
```

```c++
    17:
    18: int main(int argc, char** argv)
    19: {
00362810 55                   push        ebp
00362811 8B EC                mov         ebp,esp
00362813 81 EC C0 00 00 00    sub         esp,0C0h
00362819 53                   push        ebx
0036281A 56                   push        esi
0036281B 57                   push        edi
0036281C 8D BD 40 FF FF FF    lea         edi,[ebp-0C0h]
00362822 B9 30 00 00 00       mov         ecx,30h
00362827 B8 CC CC CC CC       mov         eax,0CCCCCCCCh
0036282C F3 AB                rep stos    dword ptr es:[edi]
0036282E B9 27 F0 36 00       mov         ecx,offset _D37E0FB1_main@cpp (036F027h)
00362833 E8 4D EA FF FF       call        @__CheckForDebuggerJustMyCode@4 (0361285h)
    20: 	function();
00362838 E8 F5 E7 FF FF       call        function (0361032h)
    21: 	function(10.0);
0036283D 83 EC 08             sub         esp,8
00362840 F2 0F 10 05 70 9B 36 00 movsd       xmm0,mmword ptr [__real@4024000000000000 (0369B70h)]
00362848 F2 0F 11 04 24       movsd       mmword ptr [esp],xmm0
0036284D E8 6A EA FF FF       call        function (03612BCh)
00362852 83 C4 08             add         esp,8
    22: 	function(10.0f);
00362855 51                   push        ecx
00362856 F3 0F 10 05 7C 9B 36 00 movss       xmm0,dword ptr [__real@41200000 (0369B7Ch)]
0036285E F3 0F 11 04 24       movss       dword ptr [esp],xmm0
00362863 E8 18 EA FF FF       call        function (0361280h)
00362868 83 C4 04             add         esp,4
    23: 	return 0;
0036286B 33 C0                xor         eax,eax
    24: }

```

## 分析汇编
- 函数重载的实现是通过name mangling实现的可以观察汇编中的function(内存地址)，其内存地址是不相同的。
- `E8 F5 E7 FF FF       call        function (0361032h)`中的地址`E8`表示的是调用函数，仔细研究Iter机器码白皮书里面有定义。
- `E8 4D EA FF FF`+` E8 F5 E7 FF FF` 机器码是按顺序执行的，其内存地址是连续的不会浪费内存`00362833`+`00362838` (注：8位(0，1)=1字节，正好两个十六位代表8个0，1数字序列是1个字节，内存地址中间相差五个字节)

