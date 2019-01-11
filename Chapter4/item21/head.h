// -----Demo 1.-----
class Rational {
public:
  Rational(int numerator = 0, int denominator = 1) :
  n(numerator), d(denominator) 
  {};

private:
  int n, d;
  // friend Rational operator*(const Rational &lhs, const Rational &rhs);

  // -----Bad code 1.stack-based-----
  // friend const Rational& operator* (const Rational& lhs, const Rational& rhs) {
  //   Rational result(lhs.n * rhs.n, lhs.d * rhs.d); // 警告！糟糕的代码！
  // }

  // -----Bad code 2.heep-based-----
  // friend const Rational& operator* (const Rational& lhs, const Rational& rhs) {
  //   Rational *result = new Rational(lhs.n * rhs.n, lhs.d * rhs.d); // 更糟糕的代码！
  //   return *result;
  // }

  // -----Bad code 3.static对象-----
  // friend Rational& operator* (const Rational& lhs, const Rational& rh) { // 又一堆烂代码
  //   static Rational result; // static对象
  //   return result;
  // }

  friend inline const Rational operator* (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
  }

  friend bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.n == rhs.n && lhs.d == rhs.d);
  }
};
