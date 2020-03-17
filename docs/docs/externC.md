<!--
 * @Description:
 * @version:
 * @Author: colley
 * @Date: 2020-03-14 21:42:33
 * @LastEditors: colley
 * @LastEditTime: 2020-03-15 18:31:28
 -->

## extern "C"

- 被`extern "C"`修饰的代码会按照C语言的方式去编译。
- 如果函数同时有声明和实现，要让函数声明被`extern "C"`修饰，函数实现可以不修饰。
- 如果`*.c`对应的`*.h`声明函数加了`extern "C"`，由于C语言是不认识`extern "C"`关键字，会出现其他`*.c`文件引用声明了`extern "C"`的`*.c`文件会出现错误。所以引用了`#ifdef __cplusplus`
```c++
#program once

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int sum(int value, int value2);

#ifdef __cplusplus
}
#endif // __cplusplus
```
!!! NOTE

- 防止重复包含我们经常使用`#ifndef`,`#ifdef`,`#endif`或者`#program once`,但是`#program once`不是适用于所有的编译器。
