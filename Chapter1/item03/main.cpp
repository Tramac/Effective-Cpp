#include <iostream>
#include <vector>
#include <string>
#include "head.h"

using namespace std;

// Demo 1.
char greeting[] = "Hello";
char *p_1 = greeting;	// 两者都不是const
const char *p_2 = greeting;	// 所指物是const
char *const p_3 = greeting;	// 指针是const
const char *const p_4 = greeting;	// 两者都是const

// Demo 2.
void f1(const Widget* pw) {

}

void f2(Widget const * pw) {

}

// Demo 4.
const Rational operator*(const Rational &lhs, const Rational &rhs);

// Demo 5.
void print(const TextBlock& ctb) {
    cout << "const TextBlock: " << ctb[0] << endl;
}

// Demo 7.
std::size_t CTextBlock2::length() const {
    if (!lengthIsValid) {
	// textLength = std::strlen(pText);	// 错误！在const成员函数内不能赋值给textLength和lengthIsValid
	// lengthIsValid = true;
    }
    return textLength;
}

// Demo 8.
std::size_t CTextBlock3::length() const {
    if (!lengthIsValid) {
	textLength = std::strlen(pText);
    }
    return textLength;
}

int main()
{
    // -------Demo 2-------
    const Widget* pw_1;
    f1(pw_1);
    f2(pw_1);

    // -------Demo 3. 声明const迭代器-------
    std::vector<int> vec;
    vec.push_back(0);
    const std::vector<int>::iterator iter = vec.begin();
    *iter = 10;
    // ++iter; // 错误！iter是const
    std::vector<int>::const_iterator cIter = vec.begin();
    // *cIter = 10; // 错误！*cIter是const
    ++cIter;

    // -------Demo 5. const成员实现重载-------
    TextBlock tb("Hello");
    cout << "TextBlock: " << tb[0] << endl;	// 调用non-const
    const TextBlock ctb("World");
    cout << "const TextBlock: " << ctb[0] << endl;	// 调用const
    print(ctb);

    // -------Demo 6. TextBlock-like class-------
    const CTextBlock cctb("Hello");
    char *pc = &cctb[0];
    *pc = 'J';
    cout << "pc: " << *pc << endl;

    return 0;
}
