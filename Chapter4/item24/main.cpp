#include "head.h"

// -----Demo 2.non-member函数-----
const Rational2 operator*(const Rational2& lhs, const Rational2& rhs) {
    return Rational2(lhs.numerator() * rhs.numerator(),
                     lhs.denominator() * rhs.denominator());
}

int main()
{
    // -----Demo 1.-----
    Rational oneEighth(1, 8);
    Rational oneHalf(1, 2);
    Rational result = oneHalf * oneEighth;
    result = result * oneEighth;

    // -----Demo 2.混合式算术-----
    result = oneHalf * 2; // 没问题
    // result = 2 * oneHalf; // 错误！

    Rational2 oneFourth(1, 4);
    Rational2 result2;
    result2 = oneFourth * 2;
    result2 = 2 * oneFourth;

    return 0;
}
