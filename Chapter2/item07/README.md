# 条款07：为多态基类声明virtual析构函数

**1.删除derived class对象时存在的问题。**<br>
C++明确指出，当derived class对象经由一个base class指针被删除，而该base class带着一个non-virtual析构函数，其结果未有定义——实际执行时通常发生的是对象的derived成分没被销毁。这种“局部销毁”现象通常会产生资源泄露、败坏数据，浪费时间等问题。

**2.消除“局部销毁”问题的方法。**<br>
给base class一个virtual析构函数。此后删除derived class对象时整个对象都会被销毁。<br>
base class中除了析构函数之外通常还有其它virtual函数。<br>
任何class只要带有virtual函数都几乎确定应该也有一个virtual析构函数，如果class不含virtual函数，通常表示它并不意图被用作一个base class。当class不企图被当做base class，令其析构函数为virtual往往是个馊主意。

**3.只有当class内含至少一个virtual函数，才为它声明virtual析构函数。**<br>
因为class内含virtual函数时，其对象的体积会增加。

**4.析构函数的运作方式。**<br>
最深层派生的那个class其析构函数最先被调用，然后是其每一个base class的析构函数被调用。编译器会在基类的派生类的析构函数中创建一个对基类析构函数的调用动作，所以必须为这个函数提供份定义。

## 请记住：
* polymorphic(带多态性质的)base classes应该声明一个virtual析构函数。如果class带有任何virtual函数，它就应该拥有一个virtual析构函数。
* Classes的设计目的如果不是作为base classes使用，或不是为了具备多态性，就不该声明virtual析构函数。
