#include <string>

using namespace std;

void encrypt(string& s) {
    s = "123456";
}

// -----Demo 1.-----
// 函数过早定义变量"encrypted"
string encryptPassword(const std::string& password) {
    string encrypted;
    if (password.length() < 8) {
        __throw_logic_error("Password is too short");
    }
    encrypt(encrypted); // 将加密后的密码置入变量encrypted内

    return encrypted;
}

// -----Demo 2.-----
// 函数延后"encrypted"定义，直到真正需要它-----
string encryptPassword2(const string& password) {
    if (password.length() < 8) {
        __throw_logic_error("Password is too short");
    }
    string encrypted(password); // 通过copy构造函数
    encrypt(encrypted); // 将加密后的密码置入变量encrypted内

    return encrypted;
}

int main()
{
    string encrypt = encryptPassword2("password");
    
    return 0;
}
