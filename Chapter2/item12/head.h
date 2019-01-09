#include <string>

void logCall(const std::string &funcName); // 制造一个log entry

// -----Demo 1.-----
class Custormer {
public:
  Custormer() : name("done") {}
  Custormer(const Custormer &rhs);
  Custormer &operator=(const Custormer &rhs);

private:
  std::string name;
};

Custormer::Custormer(const Custormer& rhs) : name(rhs.name) { // 复制rhs的数据
  logCall("Customer copy constructor");
}

Custormer& Custormer::operator=(const Custormer& rhs) {
  logCall("Customer copy assignment operator");
  name = rhs.name; // 复制rhs的数据
  return *this;
}

// -----Demo 2.-----
class Date {
};

class Customer2
{
public:
  Customer2() : name("done") {}
  Customer2(const Customer2 &rhs);
  Customer2 &operator=(const Customer2 &rhs);

private:
  std::string name;
  Date lastTransaction;
};

Customer2::Customer2(const Customer2& rhs) : name(rhs.name)
{
	logCall("Customer2 copy constructor");
}

Customer2& Customer2::operator=(const Customer2& rhs)
{
	logCall("Customer2 copy assignment operator");

	name = rhs.name;
	return *this;
}

// -----Demo 3.-----
class PriorityCustomer: public Custormer {
public:
  PriorityCustomer() : priority(1) {}
  PriorityCustomer(const PriorityCustomer &rhs);
  PriorityCustomer &operator=(const PriorityCustomer &rhs);

private:
  int priority;
};

PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs) : priority(rhs.priority) {
  logCall("PriorityCustomer copy constructor");
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs) {
  logCall("PriorityCustomer copy assignment operator");
  priority = rhs.priority;
  return *this;
}

// -----Demo 4.-----
class PriorityCustomer2: public Custormer {
public:
  PriorityCustomer2() : priority(1) {}
  PriorityCustomer2(const PriorityCustomer2 &rhs);
  PriorityCustomer2 &operator=(const PriorityCustomer2 &rhs);

private:
  int priority;
};

PriorityCustomer2::PriorityCustomer2(const PriorityCustomer2& rhs) : Custormer(rhs), // 调用base class的copy构造函数
priority(rhs.priority) {
  logCall("PriorityCustomer copy constructor");
}

PriorityCustomer2& PriorityCustomer2::operator=(const PriorityCustomer2& rhs) {
  logCall("PriorityCustomer copy assignment operator");
  Custormer::operator=(rhs); // 对base class成分进行赋值动作
  priority = rhs.priority;
  return *this;
}
