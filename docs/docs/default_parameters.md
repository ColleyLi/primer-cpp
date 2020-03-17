<!--
 * @Description:
 * @version:
 * @Author: colley
 * @Date: 2020-03-14 14:05:23
 * @LastEditors: colley
 * @LastEditTime: 2020-03-15 18:29:42
 -->

## C++默认参数

- C++ 允许函数设置默认参数，在调用时可以根据情况省略参数。规则如下：
	- 默认参数只能按照从最右到左的顺序，并且是连续的，不能出现默认参数和非默认参数进行交叉的格式。
	- <font color=STCAIYUN>如果函数同时有声明和实现，参数只能放在函数声明中，否则会报错：重复定义。</font>
	- 默认参数可以是常量、全局符号（全局变量、函数名）。

!!! NOTE

- C语言不存在默认参数
- 函数重载、默认参数可能会产生冲突、二义性（建议使用默认参数）

```c++
#include <iostream>

void test(int a, int b = 9)
{
	std::cout << "void test(int a, int b = 9)" << std::endl;
}


void test(int a)
{
	std::cout << "void test(int a)" << std::endl;
}

int main()
{
	test(a); //产生了二义性
	retrun 0;
}
```

### Demo以及C++默认参数本质(汇编)


```c++
#include <iostream>

int sum(int value1 =3, int value2 =5)
{
	return value1 + value2;
}

int gValue = 9;

int sum2(int value1 = gValue, int value2 = 0)
{
	return value1 + value2;
}

void test(int a) {
	std::cout << "test(int) - " << a << std::endl;
}

//函数指针初始化
void func(int v1, void(*p)(int) = test) {
	p(v1);
}

void test(int a = 0, int b = 9);

int main(int argc, char **argv)
{
	sum();
	sum(6);
	func(7);
	test();
	return 0;
}

void test(int a, int b)
{
	std::cout << "a+b: " << a + b << std::endl;
}
```

## 分析
- `sum()`和`sum(6)`在汇编中的结果对比,实现没有不同，从汇编上看他们的本质完全一样。
```C++
	30: 	sum();
01182798 6A 05                push        5
0118279A 6A 03                push        3
0118279C E8 FF E8 FF FF       call        sum (011810A0h)
011827A1 83 C4 08             add         esp,8
	31: 	sum(6);
011827A4 6A 05                push        5
	31: 	sum(6);
011827A6 6A 06                push        6
011827A8 E8 F3 E8 FF FF       call        sum (011810A0h)
011827AD 83 C4 08             add         esp,8
```
- 函数指针和指针函数的区分
	- 指针函数，简单的来说，就是一个返回指针的函数，其本质是一个函数，而该函数的返回值是一个指针。声明格式为：* 类型标识符 函数名(参数表)
	- 函数指针，其本质是一个指针变量，该指针指向这个函数。总结来说，函数指针就是指向函数的指针。声明格式：类型说明符 (*函数名) (参数)
```c++
#include<iostream>

typedef struct _Data{
	int a;
	int b;
}Data;

//指针函数
Data* f(int a,int b){
	Data * data = new Data;
	data->a = a;
	data->b = b;
	return data;
}

int main(int argc, char *argv[])
{
	//调用指针函数
	Data * myData = f(4,5);
	std::cout << "f(4,5) = " << myData->a << myData->b << std::endl;
	delete myData;
	return 0;
}
```

```c++
#include <iostream>

int add(int x,int y){
return x+y;
}
int sub(int x,int y){
	return x-y;
}
//函数指针
int (*fun)(int x,int y);

int main(int argc, char *argv[])
{
	//第一种写法
	fun = add;
	std::cout << "(*fun)(1,2) = " << (*fun)(1,2) ;
	//第二种写法
	fun = &sub;
	std::cout << "(*fun)(5,3) = " << (*fun)(5,3)  << fun(5,3)；
	return 0;
}
```
