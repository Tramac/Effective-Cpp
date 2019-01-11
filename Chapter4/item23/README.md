# 条款23：宁以non-member、non-friend替换member函数
-------------

**1.在许多方面non-member做法比member做法好。**<br>
愈多东西被封装，我们改变那些东西的能力也就越大。它使我们能够改变事物而只影响有限客户。<br>
能够访问private成员变量的函数只有class的member函数加上friend函数而已。而non-member，non-friend函数无法访问private成员变量，所以仍可以保持封装性，因为它并不增加”能够访问class内之private成分“的函数数量。<br>
原因总结：non-member，non-friend函数有较大的封装性。

**2.namespace的优点。**<br>
namespace可跨越多个源码文件而class不能。

**3.将所有便利函数放在多个头文件内但隶属同一个命名空间，意味着客户可以轻松扩展这一组便利函数。**<br>
他们需要做的就是添加更多non-member，non-friend函数到此命名空间内。

## 请记住：
* 宁可拿non-member non-friend函数替换member函数。这样做可以增加封装性、包裹弹性和机能扩充性。
