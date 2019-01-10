#include "head.h"

// -----Demo 1.pass-by-value-----
bool validateStudent(Student s) { // 函数以by value方式接受学生
    return false;
}

// -----Demo 2.pass by reference-to-const-----
bool validateStudent2(const Student& s) {
    return true;
}

// -----Demo 3.-----
void printNameAndDisplay(const Window& w) {
    std::cout << w.name();
    w.display();
}

int main()
{
    // -----Demo 1.-----
    Student plato;
    bool platoIsOk = validateStudent(plato); // 调用函数

    // -----Demo 3.-----
    Window w;
    printNameAndDisplay(w);
    
    WindowWithScrollBars wwsb;
    printNameAndDisplay(wwsb);

    return 0;
}
