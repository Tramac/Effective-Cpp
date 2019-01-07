// Demo 1.
class HomeForSale {
    public:
      HomeForSale(){}
    
    private:
      HomeForSale(const HomeForSale &); // 只有声明
      HomeForSale &operator=(const HomeForSale &);
};

// Demo 2.
class Uncopyable {
    protected: // 允许derived对象构造和析构
      Uncopyable() {}
      ~Uncopyable() {}

    private:
      Uncopyable(const Uncopyable &); // 但阻止copying
      Uncopyable &operator=(const Uncopyable &);
};

class HomeForSale2: private Uncopyable { // class不再声明copy构造函数或copy assign操作符
    public:
      HomeForSale2() {}
};
