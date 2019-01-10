#include <iostream>
#include <string>

// -----Demo 1.-----
class Person {
public:
  Person() : name("a"), address("b")
  {}
  virtual ~Person() {}

private:
  std::string name;
  std::string address;
};

class Student: public Person {
public:
  Student() : schoolName("c"), schoolAddress("d")
  {}
  ~Student() {}
private:
  std::string schoolName;
  std::string schoolAddress;
};

// -----Demo 3.-----
class Window {
public:
  std::string name() const { // 返回窗口名称
    return "window";
  }
  virtual void display() const {
    std::cout << "Display: window" << std::endl;
  }
};

class WindowWithScrollBars: public Window {
public:
  virtual void display() const {
    std::cout << "Display: window with scroll bars" << std::endl;
  }
};
