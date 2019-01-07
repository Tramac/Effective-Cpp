# 条款03：尽可能使用const
-----------------------

**1.关键字const的使用范围。**<br>
你可以用它在classes外部修饰global或namespace作用域中的常量，或修饰文件、函数、或区块作用域中被声明为static的对象。你也可以用它修饰classes内部的static和non-static成员变量。面对指针，你也可以指出指针自身、指针所指物，两者都是const。

**2.const语法规则。**<br>
如果关键字const出现在星号左边，表示被指物是常量；如果出现在星号右边，表示指针自身是常量；如果出现在星号两边，表示被指物和指针两者都是常量。<br>
如果被指物是常量，将关键字const写在类型之前与把它写在类型之后、星号之前，两者写法的意义相同。
```
void f1(const Widget* pw);
void f2(Widget const * pw);
```

**3.STL迭代器的const声明。**<br>
迭代器的作用就像个指针，声明迭代器为const就像声明指针为const一样，表示这个迭代器不得指向不同的东西，但它所指的东西的值是可以改动的。如果希望迭代器所指的东西不可被改动，需要的是const_iterator。
```
const std::vector<int>::iterator iter = vec.begin(); // iter为const迭代器
std::vector<int>::const_iterator cIter = vec.begin(); // cIter所指的东西为const
```

**4.const在函数声明时的应用。**<br>
在一个函数声明式内，const可以和函数返回值、各参数、函数自身产生关联。<br>
令函数返回一个常量值，往往可以降低因客户错误而造成的意外，而又不至于放弃安全性和高效性。
```
const Rational operator* (const Rational& lhs, const Rational& rhs);
```

**5.const成员函数。**<br>
将const实施于成员函数的目的，是为了确认该成员函数可作用于const对象身上。这样使得class接口比较容易被理解，同时使“操作const对象”成为可能。<br>
两个成员函数如果只是常量性不同，可以被重载。

**6.const成员函数的两个概念。**<br>
bitwise constness和logical constness。<br>
bitwise const认为，成员函数一旦被定义为const，那么对象中的任何成员变量都不可更改。<br>
logical const认为，一个const成员函数可以修改它所处理的对象内的某些成员变量。

**7.在const和non-const成员函数中避免重复。**<br>
有时，const成员函数和non-const成员函数由于功能的相同会存在代码重复的问题。<br>
而转型也不是一个理想的选择。<br>
一种安全的做法是：令non-const成员函数调用其const兄弟来避免代码重复。

## 请记住：
* 将某些东西声明为const可帮助编译器侦测出错误用法。const可被施加于任何作用域内的对象、函数参数、函数返回类型、成员函数本体。
* 编译器强制实施bitwise constness，但你编写程序时应该使用“概念上的常量性”。
* 当const和non-const成员函数有着实质性等价的实现时，令non-const版本调用const版本可避免代码重复。
