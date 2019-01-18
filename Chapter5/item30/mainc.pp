#include "head.h"

int main()
{
    // -----Demo 1.-----
    f(); // 这个调用将被inlined，因为它是一个正常调用
    pf(); // 这个调用或许不被inlined，因为它通过函数指针达成

    return 0;
}
