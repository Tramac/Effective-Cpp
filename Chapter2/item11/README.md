# 条款11：在operator=中处理“自我赋值”
-----------------

**1.“自我赋值”发生在对象被赋值给自己时。**<br>
```
class Widget {};
Widget w;
w = w; // 赋值给自己
```

**2.何时容易发生“自我赋值”？**<br>
一般而言，如果某段代码操作pointers或reference而它们被用来“指向多个相同类型的对象”，就需要考虑这些对象是否为同一个。

**3.证同测试。**<br>
```
Widget& Widget::operator=(const Widget& rhs) {
  if (this == &rhs) // 证同测试：如果是自我赋值，就不做任何事
    return *this;
  delete pb;
  pb = new Bitmap(*rhs.pb);
  return *this;
}
```
但是，证同测试仍然存在异常方面的麻烦。准确的说，“new Bitmap”有可能导致异常，比如分配时内存不足或因为Bitmap的copy构造函数抛出异常。

**4.让operator=具备“异常安全性”往往自动获得“自我赋值安全”的回报。**<br>
copy and swap技术。

## 请记住：
* 确保当对象自我赋值时operator=有良好行为。其中技术包括比较“来源对象”和“目标对象”的地址、精心周到的语句顺序、以及copy-and-swap。
* 确定任何函数如果操作一个以上的对象，而其中多个对象是同一个对象时，其行为仍然正确。
