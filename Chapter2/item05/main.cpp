#include <iostream>
#include "head.h"

// ----Demo 2.类构造函数的实现----
template<typename T>
NamedObject<T>::NamedObject(const char* name, const T& value) :
    nameValue(name),
    objectValue(value)
{}

template<typename T>
NamedObject<T>::NamedObject(const std::string& name, const T& value):
    nameValue(name),
    objectValue(value)
{}

// ----Demo 3.类构造函数的实现----
template<typename T>
NamedObject2<T>::NamedObject2(std::string& name, const T& value):
    nameValue(name),
    objectValue(value)
{}

int main()
{
    // ----Demo 1.编译器对默认函数的调用----
    Empty e1; // default构造函数
    Empty e2(e1); // copy构造函数
    e2 = e1; // copy assignment操作符

    // Demo 2.
    NamedObject<int> no1("Smallest Prime Number", 2);
    NamedObject<int> no2(no1); // 调用copy构造函数

    // Demo 3.
    std::string newDog("Persephone");
    std::string oldDog("Satch");
    NamedObject2<int> p(newDog, 2);
    NamedObject2<int> s(oldDog, 36);

    // 错误，C++不允许让reference改指向不同对象
    // p = s

    return 0;
}
