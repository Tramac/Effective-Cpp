# Effective-Cpp

《Effective C++》中文版--改善程序与设计的55个具体做法（第三版）学习记录<br>
坚持每天看两个条例，不求速度，只求理解透彻，请耐心静心学习！

### 1. [让自己习惯C++](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter1)
* 条款01：[视C++为一个语言联邦](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter1/item01)
* 条款02：[尽量以const,enum,inline替换#define](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter1/item02)
* 条款03：[尽可能使用const](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter1/item03)
* 条款04：[确定对象被使用之前已先被初始化](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter1/item04)

### 2. [构造/析构/赋值运算](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter2)
* 条款05：[了解C++默默编写并调用哪些函数](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter2/item05)
* 条款06：[若不想使用编译器自动生成的函数，就该明确拒绝](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter2/item06)
* 条款07：[为多态基类声明virtual析构函数](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter2/item07)
* 条款08：[别让异常逃离析构函数](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter2/item08)
* 条款09：[绝不在构造和析构过程中调用virtual函数](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter2/item09)
* 条款10：[令operator=返回一个reference to *this](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter2/item10)
* 条款11：[在operator=中处理“自我赋值”](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter2/item11)
* 条款12：[复制对象时勿忘其每一个成分](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter2/item12)

### 3. [资源管理](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter3)
* 条款13：[以对象管理资源](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter3/item13)
* 条款14：[在资源管理类中小心copying行为](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter3/item14)
* 条款15：[在资源管理类中提供对原始资源的访问](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter3/item15)
* 条款16：[成对使用new和delete时采取相同形式](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter3/item16)
* 条款17：[以独立语句将newed对象置入智能指针](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter3/item17)

### 4. [设计与声明](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter4)
* 条款18：[让接口容易被正确使用，不易被误用](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter4/item18)
* 条款19：[设计class犹如设计type](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter4/item19)
* 条款20：[宁以pass-by-reference-to-const替换pass-by-value](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter4/item20)
* 条款21：[必须返回对象时，别妄想返回其reference](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter4/item21)
* 条款22：[将成员变量声明为private](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter4/item22)
* 条款23：[宁以non-member、non-friend替换member函数](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter4/item23)
* 条款24：[若所有参数皆需类型转换，请为此采用non-member函数](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter4/item24)
* 条款25：[考虑写出一个不抛异常的swap函数](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter4/item25)

### 5. [实现](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter5)
* 条款26：[尽可能延后变量定义式的出现时间](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter5/item26)
* 条款27：[尽量少做转型动作](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter5/item27)
* 条款28：[避免返回handles指向对象内部成分](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter5/item28)
* 条款29：[为“异常安全”而努力是值得的](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter5/item29)
* 条款30：[透彻了解inlining的里里外外](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter5/item30)
* 条款31：[将文件间的编译依存关系降至最低](https://github.com/Tramac/Effective-Cpp/tree/master/Chapter5/item31)
