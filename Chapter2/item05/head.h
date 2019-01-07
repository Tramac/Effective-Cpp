#include <string>

// Demo 1.
class Empty{
};

// class Empty {
//     public:
//       Empty() {} // default构造函数
//       Empty(const Empty& rhs) {} // copy构造函数
//       ~Empty() {} // 析构函数

//       Empty& operator=(const Empty& rhs) {} // copy assignment操作符
// };

// Demo 2.
template<typename T>
class NamedObject {
    public:
      NamedObject(const char *name, const T &value);
      NamedObject(const std::string &name, const T &value);

    private:
      std::string nameValue;
      T objectValue;
};

// Demo 3.
template<typename T>
class NamedObject2 {
    public:
      // 以下构造函数如今不再接受一个const名称，因为nameValue
      // 如今是个reference-to-non-const string。先前那个char*构造函数
      // 已经过去了，因为必须有个string可供指涉。
      NamedObject2(std::string &name, const T &value);

    private:
      std::string &nameValue; // 这里是reference
      const T objectValue;
};
