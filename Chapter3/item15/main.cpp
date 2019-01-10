#include <tr1/memory>
#include "head.h"

// -----Demo 1.factory函数-----
Investment* createInvestment() {
    Investment *i = new Investment;
    return i;
}

// -----Demo 2.-----
FontHandle getFontHandle() {
    FontHandle fh;
    return fh;
}

int changeFontSize(FontHandle fh) {
    return 14;
}

int main()
{
    // -----Demo 1.-----
    std::tr1::shared_ptr<Investment> pi1(createInvestment()); // 令tr1::shared_ptr管理一笔资源
    bool taxable1 = !(pi1->isTaxFree(1)); // 经由operator->访问资源
    std::auto_ptr<Investment> pi2(createInvestment()); // 令auto_ptr管理一笔资源
    bool taxable2 = !((*pi2).isTaxFree(0)); // 经由operator*访问资源

    // -----Demo 2.-----
    Font f(getFontHandle());
    // int newFontSize = changeFontSize(f.get()); // 将Font显式转换为FontHandle
    int newFontSize = changeFontSize(f); // 将Font隐式转换为FontHandle

    Font f1(getFontHandle());
    FontHandle f2 = f1; // 错误！原意是要拷贝一个Font对象，却反而将f1隐式转换为其底部的FontHandle，然后才复制它。

    return 0;
}
