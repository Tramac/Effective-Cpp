#include <iostream>
#include <string>

// Demo 2.
class Widget {

};

// Demo 4.
class Rational {

};

// Demo 5.
class TextBlock {
    public:
      const char& operator[](std::size_t position) const {
          return text[position];
      }
      char& operator[](std::size_t position) {
          return text[position];
      }
      TextBlock(std::string s) : text(s) {
      }

    private:
      std::string text;
};

// Demo 6.
class CTextBlock {
    public:
      char& operator[](std::size_t position) const {
          return pText[position];
      }
      CTextBlock(char* c) : pText(c) {

      }
    private:
      char *pText;
};

// Demo 7.
class CTextBlock2 {
    public:
      CTextBlock2(char* c) : pText(c), lengthIsValid(false) {

      }
      std::size_t length() const;

    private:
      char *pText;
      std::size_t textLength;
      bool lengthIsValid;
};

// Demo 8.
class CTextBlock3 {
    public:
      CTextBlock3(char* c) : pText(c), lengthIsValid(false) {

      }
      std::size_t length() const;
    
    private:
      char *pText;
      mutable std::size_t textLength;
      mutable bool lengthIsValid;
};

// Demo 9.
class TextBlock4{
    public:
      const char& operator[](std::size_t position) const {
          // ...    // 边界检验
          // ...    // 志记数据访问
          // ...    // 检验数据完整性
          return text[position];
      }
      char& operator[](std::size_t position) {
          return const_cast<char &>(
              static_cast<const TextBlock4 &>(*this)
                  [position]);
      }
    private:
      std::string text;
};
