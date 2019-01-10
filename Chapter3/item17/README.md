# 条款17：以独立语句将newed对象置入智能指针
-------------

**1.造成资源泄露的原因。**<br>
当执行以下语句时，有可能发生两种操作顺序：
```
processWidget(std::tr1::shared_ptr<Widget>(new Widget), priority());
```
顺序1：<br>
(1)调用priority<br>
(2)执行"new Widget"<br>
(3)调用tr1::shared_ptr构造函数<br>
顺序1没什么问题！<br>
顺序2：<br>
(1)执行"new Widget"<br>
(2)调用priority<br>
(3)调用tr1::shared_ptr构造函数<br>
对于顺序2，假如对priority的调用导致异常，在此情况下"new Widget"返回的指针将会遗失，因为它尚未被置入tr1::shared_ptr内。这就是可能导致资源泄露的原因。

## 请记住：
* 以独立语句将new对象存储于智能指针内。如果不这样做，一旦异常被抛出，有可能导致难以察觉的资源泄露。
