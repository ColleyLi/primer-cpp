<!--
 * @Description:
 * @version:
 * @Author: colley
 * @Date: 2020-03-14 23:38:28
 * @LastEditors: colley
 * @LastEditTime: 2020-03-15 18:46:04
 -->

## 内联函数inline

- 使用inline修饰函数的声明或者实现，可以使其变成内联函数
    - 建议声明和实现都增加inline修饰
- 特点
    - 编译器会将函数调用直接展开为函数体代码
    - 可以减少函数调用的开销(调用函数需要开辟栈空间，调用结束之后还需要回收栈空间)
    - 会增大代码体积
- 注意
    - 尽量不要内联超过10行代码的函数
    - 有些函数即使声明为inline，也不一定会被编译器内联，比如递归函数
      - 使用范围：代码体积不大，反复调用的。
    - `inline`和`#define`宏都可以减少开销但是存在区别
      - `inline`多了语法检测和函数特性
      - 由于`#define`是直接替换可能不是想要的结果

```c++
void run()
{
    run()
}
```
```C++
#define sum(x) (x+x) //result: 24
inline int sum(x) { return x + x; }//result:22
int a = 10;
sum(++a);
```

### 汇编实质
- 不加inline
```c++
int sum(int v1, int v2) {
  return v1 + v2;
}
```
```c++
    39: 	int c =sum(4, 6);
00007FF6AE181034 BA 06 00 00 00       mov         edx,6
00007FF6AE181039 B9 04 00 00 00       mov         ecx,4
00007FF6AE18103E E8 BD FF FF FF       call        sum (07FF6AE181000h)
00007FF6AE181043 89 44 24 28          mov         dword ptr [c],eax
```
- 加inline
```c++
inline int sum(int v1, int v2) {
  return v1 + v2;
}
```
```c++
    39: 	int c =sum(4, 6);
00007FF7A46A1014 B8 04 00 00 00       mov         eax,4
00007FF7A46A1019 83 C0 06             add         eax,6
00007FF7A46A101C 89 44 24 28          mov         dword ptr [c],eax
```

- 有inline修饰之后直接将调用的函数拿出来，不会去调用sum函数了
