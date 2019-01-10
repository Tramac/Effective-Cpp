#include "head.h"

int main()
{
    // -----Demo 1.-----
    Mutex m; // 定义你需要的互斥器
    Lock2 m1(&m);
    Lock2 m2(m1);

    return 0;
}
