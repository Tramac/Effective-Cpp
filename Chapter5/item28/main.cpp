#include "head.h"

// -----Demo 3.-----
const Rectangle2 boundingBox(const GUIObject& obj) {
    Rectangle2 re;
    return re;
}

int main()
{
    // -----Demo 3.-----
    GUIObject *pgo;
    const Point *pUpperLeft = &(boundingBox(*pgo).upperLeft());

    return 0;
}
