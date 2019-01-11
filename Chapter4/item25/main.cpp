#include "head.h"

int main()
{
    WidgetStuff::WidgetImpl3<int> wi1(1, 2, 3);
    WidgetStuff::WidgetImpl3<int> wi2(1, 2, 3);

    WidgetStuff::Widget3<int> w1(&wi1);
    WidgetStuff::Widget3<int> w2(&wi2);

    WidgetStuff::swap(w1, w2);

    return 0;
}
