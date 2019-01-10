#include <tr1/memory>

// -----Demo 1.-----
class Investment {
public:
  bool isTaxFree(int pd) const {
    return (1 == pd);
  }
};

// -----Demo 2.-----
void releaseFont(FontHandle fh) {}
class FontHandle {
};

class Font {
public:
  explicit Font(FontHandle fh) : f(fh) { // 获得资源，采用pass-by-value，因为C API这样做
  }
  ~Font() {
    releaseFont(f); // 释放资源
  }
  FontHandle get() const {
    return f; // 显式转换函数
  }
  operator FontHandle() const {
    return f; // 隐式转换函数
  }

private:
  FontHandle f; // 原始字体资源
};
