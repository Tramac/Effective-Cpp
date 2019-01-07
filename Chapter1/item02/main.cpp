#include <iostream>
#include "head.h"

using namespace std;

// Demo 1
#define ASPECT_RATIO 1.653
// Demo 2
const double AspectRatio = 1.653;
// Demo 8.
int f(int) {}
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))
// Demo 9.
template<typename T>
inline int callWithMax(const T& a, const T& b) {
    return f(a > b ? a : b);
}
int main()
{
    // -------Demo 1: 使用#define-------
    cout << "ASPECT_RATIO: " << ASPECT_RATIO << endl;
    // -------Demo 2: 使用const替代#define------
    cout << "AspectRatio: " << AspectRatio << endl;
    // -------Demo 3: 定义常量指针-------
    cout << "authorName_c: " << authorName_c << endl;
    // -------Demo 4: 使用string对象替代char*-based---
    cout << "authorName_s: " << authorName_s << endl;
    // -------Demo 5: class专属常量-------
    GamePlayer gp;
    // -------Demo 6: 旧式编译器-------
    //const double
    //	CostEstimate::FudgeFactor = 1.35;
    // -------Demo 7: 枚举实现in class初值设定-----
    GamePlayer_e gp_e;
    // -------Demo 8: #define实现宏的缺点-------
    int a = 5, b = 0;
    cout << "a被累加二次： " << CALL_WITH_MAX(++a, b) << endl;
    cout << "a被累加一次: " << CALL_WITH_MAX(++a, b + 10) << endl;
    // -------Demo 9: 使用inline代替#define----
    a = 5, b = 0;
    cout << "a被累加二次： " << callWithMax(++a, b) << endl;
    cout << "a被累加一次: " << callWithMax(++a, b + 10) << endl;

    return 0;
}
