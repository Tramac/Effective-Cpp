class Bitmap {
};

// -----Demo 1.误删问题-----
class Widget {
public:
  Widget();
  Widget &operator=(const Widget &rhs);
private:
  Bitmap *pb; // 指针，指向一个从heap分配而得的对象
};

Widget& Widget::operator=(const Widget& rhs) { // 一份不安全的operator=实现版本
  delete pb; // 停止使用当前的bitmap
  pb = new Bitmap(*rhs.pb); // 使用rhs's bitmap的副本
  return *this; // *this和rhs有可能是同一个对象，从而delete有可能同时销毁rhs的bitmap
}

// -----Demo 2.证同测试-----
class Widget2 {
public:
  Widget2();
  Widget2 &operator=(const Widget2 &rhs);
private:
  Bitmap *pb;
};

Widget2& Widget2::operator=(const Widget2& rhs) {
  if (this == &rhs) // 证同测试：如果是自我赋值，就不做任何事
    return *this;
  delete pb;
  pb = new Bitmap(*rhs.pb);
  return *this;
}

// -----Demo 3.解决异常安全性-----
class Widget3 {
public:
  Widget3();
  Widget3 &operator=(const Widget3 &rhs);
private:
  Bitmap *pb;
};

Widget3& Widget3::operator=(const Widget3& rhs) {
  Bitmap *pOrig = pb; // 记住原先的pb，没有直接删除，不存在误删rhs的问题
  pb = new Bitmap(*rhs.pb);
  delete pOrig; // 删除原来的pb
  return *this;
}

// -----Demo 4.copy and swap-----
class Widget4 {
public:
  Widget4();
  Widget4 &operator=(const Widget4 &rhs);
  void swap(Widget4 &rhs); // 交换*this和rhs的数据

private:
  Bitmap *pb;
};

Widget4& Widget4::operator=(const Widget4& rhs) {
  Widget4 temp(rhs); // 为rhs数据制作一份复件
  swap(temp); // 将*this数据和上述复件的数据交换
  return *this;
}

void Widget4::swap(Widget4& rhs) {
}

// -----Demo 5.copy and swap自动创建副本-----
class Widget5 {
public:
  Widget5();
  Widget5 &operator=(Widget5 rhs);
  void swap(Widget5 &rhs); // 交换*this和rhs的数据

private:
  Bitmap *pb;
};

Widget5& Widget5::operator=(Widget5 rhs) { // rhs是被传对象的一份复件
  swap(rhs); // 这里是pass by value
  return *this;
}

void Widget5::swap(Widget5& rhs) {
}
