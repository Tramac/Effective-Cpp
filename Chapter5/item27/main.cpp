#include "head.h"
#include <tr1/memory>
#include <vector>

// -----Demo 1.-----
void doSomeWork(const Widget& w) {
}

// -----Demo 6.-----
typedef std::vector<std::tr1::shared_ptr<Window>> VPW;

// -----Demo 7.-----
typedef std::vector<std::tr1::shared_ptr<SpecialWindow3>> VPSW;

// -----Demo 8.-----
typedef std::vector<std::tr1::shared_ptr<Window2>> VPW2; // 容器，内含指针，指向所有可能的Window类型

int main()
{
    // -----Demo 1.-----
    doSomeWork(Widget(15)); // 以一个int加上“函数风格”的转型动作创建一个Widget
    doSomeWork(static_cast<Widget>(15)); // 以一个int加上“C++风格”的转型动作创建一个Widget

    // -----Demo 2.-----
    int x, y;
    x = 1, y = 2;
    double d = static_cast<double>(x) / y; // x除以y，使用浮点数除法

    // -----Demo 3.-----
    Derived de;
    Base *pb = &de; // 隐喻的将Derived*转换为Base*

    // ------Demo 6.不希望做的方法------
    VPW winPtrs;
    for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter) {
        if (SpecialWindow3* psw = dynamic_cast<SpecialWindow3*>(iter->get())) // 不希望使用dynamic_cast
            psw->blink();
    }

    // -----Demo 7.-----
    VPSW winPtrs2;
    for (VPSW::iterator iter = winPtrs2.begin(); iter != winPtrs2.end(); iter++)
        (*iter)->blink(); // 建议这样使用

    // -----Demo 8.-----
    VPW2 winPtrs3;
    for (VPW2::iterator iter = winPtrs3.begin(); iter != winPtrs3.end(); ++iter)
        (*iter)->blink(); // 注意这里没有dynamic_cast

    return 0;
}
