#include <vector>

class WidgetImpl {
public:
  WidgetImpl(int x, int y, int z) :
  a(x), b(y), c(z)
  {}
private:
  int a, b, c;
  std::vector<double> v;
};

class Widget {
public:
  Widget(WidgetImpl* wi) : pImpl(wi) {}
  Widget(const Widget &rhs);
  Widget& operator=(const Widget& rhs) {
    *pImpl = *(rhs.pImpl);
    return *this;
  }

private:
  WidgetImpl *pImpl; // 指针，所指对象内含Widget数据
};

// -----Demo 1.特化-----
// namespace std {
//   template<>  // 这是std::swap针对“T是Widget”的特化版本，目前还不能通过编译
//   void swap<Widget>(Widget& a, Widget& b) {
//     swap(a.pImpl, b.pImpl); // 置换Widgets时只要置换它们的pImpl指针就好
//   }
// }

template<typename T>
class WidgetImpl2 {
public:
  WidgetImpl2(int x, int y, int z) :
  a(x), b(y), c(z)
  {}
private:
  int a, b, c;
  std::vector<double> v;
};

template<typename T>
class Widget2 {
public:
  Widget2(WidgetImpl2<T>* wi) : pImpl(wi) {}
  void swap(Widget2& other) {
    using std::swap;
    swap(pImpl, other.pImpl); // 若要置换Widget就置换其pImpl指针
  }

private:
  WidgetImpl2<T> *pImpl; // 指针，所指对象内含Widget数据
};

// -----Demo 2.特例化-----
// namespace std {
//   template<typename T>
//   void swap<Widget2>(Widget2& a, Widget2& b) { // 错误！不合法！
//     a.swap(b); // 若要置换Widget，调用其swap成员函数
//   }
// }

// -----Demo 3.重载实现-----
// namespace std {
//   template<typename T> //std::swap的一个重载版本
//   void swap(Widget2<T>& a, Widget2<T>& b) { // 注意swap之后没有“<...>"，这同样不合法
//     a.swap(b);
//   }
// }

// -----Demo 4.声明一个non-member swap-----
namespace WidgetStuff {
  template<typename T>
  class WidgetImpl3 {
  public:
    WidgetImpl3(int x, int y, int z) :
    a(x), b(y), c(z)
    {}
  private:
    int a, b, c;
    std::vector<double> v;
  };

  template<typename T>
  class Widget3 {
  public:
    Widget3(WidgetImpl3<T>* wi) : pImpl(wi) {}
    void swap(Widget3& other) {
      using std::swap;
      swap(pImpl, other.pImpl);
    }

  private:
    WidgetImpl3<T> *pImpl; // 指针，所指对象内含Widget数据
  };

  template<typename T> // non-member swap函数
  void swap(Widget3<T>& a, Widget3<T>& b) { // 这里并不属于std命名空间
    a.swap(b);
  }
}
