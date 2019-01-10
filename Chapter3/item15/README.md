# 条款15：在资源管理类中提供对原始资源的访问
----------------

**1.将RAII class对象转换为其所内含之原始资源。**<br>
显示转换和隐式转换。<br>
tr1::shared_ptr和auto_ptr都提供一个get成员函数，用来执行显式转换，也就是它会返回智能指针内部的原始指针（的复件）。
```
std::tr1::shared_ptr<Investment> pInv(createInvestment());
int dayHeld(const Investment* pi); // 返回投资天数
// int days = daysHeld(pInv); // 错误！
int days = dayHeld(pInv.get()); // 将pInv内的原始指针传给daysHeld
```
就像所有智能指针一样，tr1::shared_ptr和auto_ptr也重载了指针取值操作符(operator->和operator*)，它们允许隐式转换至底部原始指针。

## 请记住：
* APIs往往要求方位原始数据，所以每一个RAII class应该提供一个”取得其所管理之资源“的办法。
* 对原始资源的访问可能经由显式转换或隐式转换。一般而言显式转换比较安全，但隐式转换对客户比较方便。
