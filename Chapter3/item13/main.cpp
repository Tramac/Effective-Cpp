#include <tr1/memory>
#include "head.h"

// -----Demo 1.factory function-----
Investment* createInvestment() { // 返回指针，指向Investment继承体系内的动态分配对象。
    Investment *i = new Investment; // 调用者有责任删除它
    return i;
}

// -----Demo 2.删除对象-----
void f() {
    Investment *pInv = createInvestment(); // 调用factory函数
    delete pInv; // 释放pInv所指对象
}

// -----Demo 3.智能指针-----
void f2() {
    std::auto_ptr<Investment> pInv(createInvestment()); // 调用factory函数，经由auto_ptr的析构函数自动删除pInv
}

// -----Demo 4.auto_ptr的唯一拥有性-----
void f3() {
    std::auto_ptr<Investment> pInv1(createInvestment()); // pInv1指向createInvestment返回物
    std::auto_ptr<Investment> pInv2(pInv1); // 现在pInv2指向对象，pInv1被设为null
    pInv1 = pInv2; // 现在pInv1指向对象，pInv2被设为null
}

// -----Demo 5.RCSP-----
void f4() {
    std::tr1::shared_ptr<Investment> pInv1(createInvestment()); // pInv1指向createInvestment返回物
    std::tr1::shared_ptr<Investment> pInv2(pInv1); // pInv1和pInv2指向同一个对象
    pInv1 = pInv2; // 同上，无任何改变
} // pInv1和pInv2被销毁，它们所指的对象也就被自动销毁

int main()
{
    f4();

    return 0;
}
