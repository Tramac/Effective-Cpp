// -----Demo 1.-----
class Transaction { // 所有交易的base class
public:
  Transaction();
  virtual void logTransaction() const = 0; // 做出一份因类型不同而不同的日志记录
};

Transaction::Transaction() { // base class构造函数实现
  logTransaction();
}

class BuyTransaction : public Transaction{
public:
  virtual void logTransaction() const;
};

class SellTransaction : public Transaction {
public:
  virtual void logTransaction() const;
};

// -----Demo 2.-----
class Transaction2 {
public:
  Transaction2() {
    init(); // 调用non-virtual
  };
  virtual void logTransaction() const = 0;

private:
  void init() {
    logTransaction();
  };
};

// -----Demo 3.-----
class Transaction3 {
public:
  explicit Transaction3(const std::string &logInfo);
  void logTransaction(const std::string &logInfo) const; // 现在是non-virtual函数
};

Transaction3::Transaction3(const std::string& logInfo) {
  logTransaction(logInfo);
}

class BuyTransaction3 : public Transaction3 {
public:
  BuyTransaction3(int x) : Transaction3(createLogString(x))
  {}
private:
  static std::string createLogString(int x) {
    return "done";
  }
};
