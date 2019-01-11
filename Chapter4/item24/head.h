// -----Demo 1.-----
class Rational {
public:
  Rational(int numerator = 0, int denominator = 1) : // 构造函数刻意不为explicit，
  n(numerator), d(denominator)                       // 允许int-to-Rational隐式转换
  {}
  int numerator() const { return n; } // 分子分母的访问函数
  int denominator() const { return d; }

  const Rational operator* (const Rational& rhs) const {
    return Rational(n * rhs.numerator(), d * rhs.denominator());
  }

private:
  int n, d;
};

// -----Demo 2.-----
class Rational2 {
public:
  Rational2(int numerator = 0, int denominator = 1) :
  n(numerator), d(denominator)
  {}
  int numerator() const { return n; }
  int denominator() const { return d; }

private:
  int n, d;
};
