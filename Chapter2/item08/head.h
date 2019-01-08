// -----Demo 1.-----
class DBConnection {
public:
  static DBConnection create() { // 函数返回DBConnection对象
    static DBConnection db;
	  return db;
  };
  void close(); // 关闭联机，失败则抛出异常
};

// -----Demo 2.-----
class DBConn { // 该class用来管理DBConnection对象
public:
  DBConn(DBConnection database): db(database)
  {}
  ~DBConn(){ // 确保数据库连接总是会关闭
    try { db.close(); }
    catch (...) {
      std::abort(); // 制作运转记录，记下对close的调用失败
    }
  }

private:
  DBConnection db;
};

// -----Demo 3.-----
class DBConn2 {
public:
  DBConn2(DBConnection database) : db(database), closed(false) 
  {}
  ~DBConn2() {
    if (!closed) {
      try {
        db.close(); // 关闭连接
      }
      catch (...) { // 如果关闭动作失败，记录下并结束程序，或吞下异常
        // 制作运转记录，记下对close的调用失败
        std::abort();
      }
    }
  }
  void close() { // 供客户使用的新函数
    db.close();
    closed = true;
  }

private:
  DBConnection db;
  bool closed;
};
