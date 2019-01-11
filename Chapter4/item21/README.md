# 条款21：必须返回对象时，别妄想返回其reference
-------------------

**1.所谓reference只是个名称，代表某个既有对象。**<br>
任何时候看到一个reference声明式，你都应该立刻问自己，它的另一个名称是什么？因为它一定是某物的另一个名称。

**2.函数创建新对象的途径。**<br>
在stack空间或在heap空间创建。<br>
如果定义一个local变量，就是在stack空间创建对象。而heap-based对象由new创建。

**3.任何函数如果返回一个reference指向某个local对象，都将一败涂地。**<br>
因为local对象在函数退出前被销毁了，它返回的reference指向一个”从前的“、已经被销毁的对象。

**4.一个“必须返回新对象”的函数的正确写法。**<br>
就让那个函数返回一个新对象。

## 请记住：
* 绝不要返回pointer或reference指向一个local stack对象，或返回reference指向一个heap-allocated对象，或返回pointer或reference指向一个local static对象而有可能同时需要多个这样的对象。
