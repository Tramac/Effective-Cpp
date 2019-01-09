# 条款12：复制对象时勿忘其每一个成分
------------------

**1.copying函数。**<br>
copy构造函数和copy assignment操作符。

**2.对于自己定义的copying函数，如果代码不完全，编译器不会提醒。**<br>
如果你为class添加一个成员变量，你必须同时修改copying函数。

**3.任何时候为derived class撰写copying函数时，必须小心地也复制其base class成分。**<br>
那些成分往往是private，所以无法直接访问它们，你应该让derived class的copying函数调用相应的base class函数。

**4.“复制每一个成分”。**<br>
当你编写了一个copying函数：<br>
(1)复制所有的local成员变量。<br>
(2)调用所有base classes内的适当的copying函数。

**5.不该令copy assignment操作符调用copy构造函数，令copy构造函数调用copy assignment操作符同样无意义。**
如果你发现你的copy构造函数和copy assignment操作符有相近的代码，消除重复代码的做法是，建立一个新的成员函数给两者调用。这样的函数往往是private而且常被命名为init。

## 请记住：
* Copying函数应该确保复制“对象内的所有成员变量”及“所有base class成分”。
* 不要尝试以某个copying函数实现另一个copying函数。应该将共同机能放进第三个函数中，并由两个copying函数共同调用。
