#include <string>

// -----Demo 1.-----
inline void f() {} // 假设编译器有意愿inline“对f的调用”
void (*pf)() = f;

// -----Demo 2.-----
class Base {
private:
  std::string bm1, bm2;
};

class Derived: public Base {
public:
  Derived() {} // 函数并不是空白，并不适合声明为inline
private:
  std::string dm1, dm2, dm3;
};
