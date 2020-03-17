<!--
 * @Description:
 * @version:
 * @Author: colley
 * @Date: 2020-03-15 13:09:55
 * @LastEditors: colley
 * @LastEditTime: 2020-03-15 18:42:28
 -->
## 引用
- 在C语言中，使用指针（Pointer）可以间接获取、修改某个变量的值
- 在C++中，使用引用（Reference）可以起到跟指针类似的功能
- 注意:
    - 引用相当于是变量的别名（基本数据类型、枚举、结构体、类、指针、数组等，都可以有引用）
    - 对引用做计算，就是对引用所指向的变量做计算
    - 在定义的时候就必须初始化，一旦指向了某个变量，就不可以再改变，“从一而终”
    - 可以利用引用初始化另一个引用，相当于某个变量的多个别名
    - 不存在[引用的引用、指向引用的指针、引用数组]
- 引用存在的价值之一：比指针更安全、函数返回值可以被赋值
- 引用的本质就是指针，只是编译器削弱了它的功能，所以引用就是弱化了的指针
- 一个引用占用一个指针的大小

## 汇编分析
- 初始化引用变量从一而终
```c++
int heading1 = 20;
int heading2 = 9;
int &refHeading = heading1;
refHeading = heading2; //只是进行赋值操作不是创建引用
```
- 反复调用`swap(int&,int&)`函数好像不符合"从一而终"的概念是因为，每次调用都会创建新的栈空间，每一次调用都会重新创建新的引用
```c++
void swap(int &v1, int &v2) {
int tmp = v1;
v1 = v2;
v2 = tmp;
}
```
- 引用是弱化的指针，占用内存大小和指针没有区别
    - 8086 (16bit)两字节
    - x86 (32bit)四字节
    - x64 (64bit)八字节
- 间接证明
```c++
struct Student {int & age;}
struct Student2 {int* age;}
struct Student3 {int age;}

std::cout << "sizieof(student): " << sizeof(Student) << std::endl;
std::cout << "sizieof(student2): " << sizeof(Student2) << std::endl;
std::cout << "sizieof(student3): " << sizeof(Student3) << std::endl;
```
- 错误的证明方式（原因：refAge使用等价age变量，所以后面所有的`sizeof()`相当于对`age`和对`age`的指针进行大小的判断）
```c++
int age = 19;
int &refAge = age;
std::cout << sizeof(refAge) << std::endl;
std::cout << sizeof(&refAge) << std::endl;
```
- 直接证明方法（指针和引用汇编代码的实现一摸一样）
```c++
    39: 	int a;
    40: 	int *p = &a;
00007FF68D961013 48 8D 44 24 08       lea         rax,[a]
00007FF68D961018 48 89 04 24          mov         qword ptr [rsp],rax
    41: 	*p = 30;
00007FF68D96101C 48 8B 04 24          mov         rax,qword ptr [rsp]
00007FF68D961020 C7 00 1E 00 00 00    mov         dword ptr [rax],1Eh
```
```c++
    39: 	int a;
    40: 	int &p = a;
00007FF622D11013 48 8D 44 24 08       lea         rax,[a]
00007FF622D11018 48 89 04 24          mov         qword ptr [rsp],rax
    41: 	p = 30;
00007FF622D1101C 48 8B 04 24          mov         rax,qword ptr [rsp]
00007FF622D11020 C7 00 1E 00 00 00    mov         dword ptr [rax],1Eh
```

!!! NOTE

- `00007FF68D961013`前面的地址不过是虚内存地址，编译器会将虚地址对应到内存的实际地址中
