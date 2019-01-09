# 条款10：令operator=返回一个reference to *this
----------------------

**1.实现“连锁赋值”。**<br>
为了实现“连锁赋值”，赋值操作符必须返回一个reference指向操作符的左侧实参。

## 请记住：
* 令赋值操作符返回一个reference to *this。
