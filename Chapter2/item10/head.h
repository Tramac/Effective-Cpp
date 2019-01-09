// -----Demo 1.-----
class Widget {
public:
  Widget& operator=(const Widget& rhs) { // 返回类型是个reference,指向当前对象
    return *this; //返回左侧对象
  }
};

// -----Demo 2.-----
class Widget2 {
public:
  Widget2& operator=(const Widget2& rhs) {
    return *this;
  }
  Widget2& operator+=(const Widget2& rhs) { // 该协议适用于+=,-=,*=等
    return *this;
  }
  Widget2& operator=(int rhs) { // 此函数也试用，即使此操作符的参数类型不符协定
    return *this;
  }
};
