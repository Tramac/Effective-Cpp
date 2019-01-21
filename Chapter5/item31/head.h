#include <string>
#include <tr1/memory>
#include "date.h"
#include "address.h"
#include "PersonImpl.h"

// -----Demo 1.-----
class Person {
public:
  Person(const std::string &name, const Date &birthday, const Address &addr):
  theName(name), theBirthDate(birthday), theAddress(addr)
  {}
  std::string name() const;
  std::string birthDate() const;
  std::string address() const;

private:
  std::string theName; // 实现细目
  Date theBirthDate; // 实现细目
  Address theAddress; // 实现细目
};

// -----Demo 2.分割为两个类，一个提供接口，另一个负责实现该接口-----
// class PersonImpl; // Person实现类的前置声明
// class Date2; // Person接口用到的class的前置声明
// class Address2;

class Person2 {
public:
  Person2() {}
  Person2(const std::string &name, const Date &birthday, const Address &addr);
  std::string name() const;
  std::string birthDate() const;
  std::string address() const;
private:
  std::tr1::shared_ptr<PersonImpl> pImpl; // 指针，指向实现物
};

// -----Demo 3.-----
class Person3 {
public:
  Person3() {}
  Person3(const std::string &name, const Date &birthday, const Address &addr);
  virtual ~Person3() {}

  virtual std::string name() const = 0;
  virtual std::string birthDate() const = 0;
  virtual std::string address() const = 0;
};

// -----Demo 4.-----
class RealPerson: public Person3 {
public:
  RealPerson() {}
  RealPerson(const std::string& name, const Date& birthday, const Address& addr) :
  theName(name), theBirthDate(birthday), theAddress(addr)
  {}
  virtual ~RealPerson() {}
  std::string name() const; // 这些函数的实现代码并不显示于此，但它们很容易想象
  std::string birthDate() const;
  std::string address() const;

  static std::tr1::shared_ptr<Person3> create(const std::string& name,
  const Date& birthday, const Address& addr) {
    return std::tr1::shared_ptr<Person3>(new RealPerson(name, birthday, addr));
  }

private:
  std::string theName;
  Date theBirthDate;
  Address theAddress;
};
