# 条款20：宁以pass-by-reference-to-const替换pass-by-value
-----------------

**1.缺省情况下C++以by value方式传递对象至函数。**<br>
除非你另外指定，否则函数参数都是以实际实参的复件(副本)为初值，而调用端所获得的亦是函数返回值的一个复件。这些复件(副本)系由对象的copy构造函数产出，这可能使得pass-by-value成为昂贵的操作。

**2.pass by reference-to-const的优点。**<br>
没有任何构造函数和析构函数被调用，因为没有任何新对象被创建。参数声明中的const极为重要。以by reference方式传递参数也可以避免slicing(对象切割)问题。

**3.pass by value往往比pass by reference的效率高些。**<br>
referece往往以指针实现出来，因此pass by reference通常意味真正传递的是指针。

**4.一般而言，”pass-by-value并不昂贵“的唯一对象就是内置类型和STL的迭代器和函数对象。**<br>
至于其他任何东西都尽量以pass-by-reference-to-const替换pass-by-value。

## 请记住：
* 尽量以pass-by-reference-to-const替换pass-by-value。前者通常比较高效，并可避免切割问题。
* 以上规则并不适用于内置类型，以及STL的迭代器和函数对象。对它们而言，pass-by-value往往比较适当。
