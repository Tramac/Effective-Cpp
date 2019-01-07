#include <iostream>
#include "head.h"

using namespace std;

// ----Demo 2.ABEntry构造函数赋值----
ABEntry::ABEntry(const std::string& name, const std::string& address,
				 const std::list<PhoneNumber>& phones) {
    theName = name; // 这些都是赋值，而非初始化
    theAddress = address;
    thePhones = phones;
    numTimesConsulted = 0;
}

// ----Demo 3.使用member init list替换赋值----
ABEntry::ABEntry(const std::string& name, const std::string& address,
				 const std::list<PhoneNumber>& phones)
    :theName(name), // 现在，这些都是初始化
    theAddress(address),
    thePhones(phones),
    numTimesConsulted(0)
{} // 现在，构造函数本体不必有任何动作

// ----Demo 5.----
Directory::Directory() {
    std::size_t disks = tfs.numDisks();
}

// ----Demo 6.----
Directory2::Directory2() {
    std::size_t disks = tfs2().numDisks();
}

int main()
{
    // ----Demo 1.内置类型初始化----
    int x = 0;
    const char *text = "A C-style string";
    double d;
    std::cin >> d;

    // Demo 5.
    Directory tempDir();

    return 0;
}
