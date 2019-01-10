#include <tr1/memory>
#include "head.h"

int priority() {
    return 1;
}

void processWidget(std::tr1::shared_ptr<Widget> pw, int priority) {
}

int main()
{
    // -----Demo 1.-----
    // processWidget(new Widget, priority()); // 错误，函数要求是tr1::shared_ptr<Widget>，而new生成的是Widget*

    // -----Demo 2.-----
    // processWidget(std::tr1::shared_ptr<Widget>(new Widget), priority()); // 容易造成内存泄露

    // -----Demo 3.-----
    std::tr1::shared_ptr<Widget> pw(new Widget); // 在单独语句内以智能指针存储new所得对象
    processWidget(pw, priority()); // 这个调用动作绝不至于造成泄露

    return 0;
}
