#include <string>
#include <list>

// Demo 2.
class PhoneNumber{
};

class ABEntry {
    public:
      ABEntry(const std::string &name, const std::string &address,
              const std::list<PhoneNumber> &phones);

    private:
      std::string theName;
      std::string theAddress;
      std::list<PhoneNumber> thePhones;
      int numTimesConsulted;
};

// Demo 4.

class FileSystem {
    public:
      std::size_t numDisks() const {
          return 5;
      };
};
extern FileSystem tfs;

// Demo 5.
class Directory {
    public:
      Directory();
};

// Demo 6.
class FileSystem2 {
    public:
      std::size_t numDisks() const {
          return 5;
      };
};
FileSystem2& tfs2() { // 这个函数用来替换tfs对象；它在FileSystem2 class中可能是个static,
    static FileSystem2 fs; // 定以并初始化一个local static对象，
    return fs; // 返回一个reference指向上述对象
}

class Directory2 {
    public:
      Directory2();
};
Directory2& tempDir2() {
    static Directory2 td;
    return td;
}
