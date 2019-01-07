# 条款05：了解C++默默编写并调用哪些函数
--------------------

**1.什么时候empty class不再是个empty class呢？**<br>
当C++处理过它之后。<br>
如果自己没声明，编译器就会为它声明一个copy构造函数、一个copy assignment操作符和一个析构函数。此外如果没有声明任何构造函数，编译器也会为你声明一个default构造函数。所有这些函数都是public且inline。<br>
假如自己已经声明了一个构造函数，编译器将不再为它创建default构造函数。

**2.内含reference成员的class的情况。**<br>
对于内含reference成员的class内支持赋值操作，必须自己定义copy assignment操作符。面对“内含const成员”的classes，编译器的反应也一样。

## 请记住：
* 编译器可以暗自为class创建default构造函数、copy构造函数、copy assignment操作符，以及析构函数。
