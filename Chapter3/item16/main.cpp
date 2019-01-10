#include <string>

// -----Demo 2.-----
typedef std::string AddressLines[4]; // 每个人的地址有4行，每行是一个string

int main()
{
    // -----Demo 1.-----
    std::string *stringPtr1 = new std::string;
    std::string *stringPtr2 = new std::string[100];
    delete stringPtr1; // 删除一个对象
    delete[] stringPtr2; // 删除一个由对象组成的数据

    // -----Demo 2.-----
    std::string *pal = new AddressLines; // 注意，"new AddressLines"返回一个string*，就像"new string[4]"一样
    // delete pal; // 错误
    delete[] pal;

    return 0;
}
