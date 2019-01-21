#include "head.h"
#include "PersonImpl.h"
#include <tr1/memory>

// -----Demo 2.-----
// Person2::Person2(const std::string& name, const Date& birthday, const Address& addr) :
// pImpl(new PersonImpl(name, birthday, addr))
// {}

// std::string Person2::name() const {
//     return pImpl->name();
// }

int main()
{
    // -----Demo 4.-----
    std::string s = "hello";
    Date d;
    Address a;

    std::tr1::shared_ptr<Person3> pp(RealPerson::create(s, d, a));

    return 0;
}
