#include <string>
#include "date.h"
#include "address.h"

class PersonImpl {
public:
  PersonImpl(const std::string &name, const Date &birthday, const Address &addr);
  std::string name() const { return theName; };
  std::string birthDate() const { return "data"; };
  std::string address() const { return "addr"; };

private:
  std::string theName;
  Date theBirthDate;
  Address theAddress;
};
