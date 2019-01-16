// -----Demo 1.-----
class Widget {
public:
  explicit Widget(int size) : mysize(size) {};
private:
  int mysize;
};

// -----Demo 3.-----
class Base {
};

class Derived: public Base {
};

// -----Demo 4.-----
class Window {
public:
  virtual void onResize() {}
};

class SpecialWindow: public Window {
public:
  virtual void onResize() {
    static_cast<Window>(*this).onResize(); // 将*this转型为Window，然后调用其onResize，错误！
  }
};

// -----Demo 5.-----
class SpecialWindow2: public Window {
public:
  virtual void onResize() {
    Window::onResize(); // 调用Window::onResize作用于*this身上
  }
};

// ------Demo 6.-----
class SpecialWindow3: public Window {
public:
  void blink();
};

// -----Demo 8.-----
class Window2 {
public:
  virtual void onResize() {}
  virtual void blink() {} // 缺省实现代码“什么也没做”
};

class SpecialWindow4: public Window2 {
public:
  virtual void blink(){}; // 在此class内，blink做某些事
};
