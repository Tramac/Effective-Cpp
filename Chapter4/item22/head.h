// -----Demo 1.-----
class AccessLevels {
public:
  int getReadOnly() const { return readOnly; }
  void setReadWrite(int value) { readWrite = value; }
  int getReadWrite() const { return readWrite; }
  void setWriteOnly(int value) { writeOnly = value; }

private:
  int noAccess; // 对此int无任何访问动作
  int readOnly; // 对此int做只读访问
  int readWrite; // 对此int做读写访问
  int writeOnly; // 对此int做唯写访问
};

// -----Demo 2.-----
class SpeedDataCollection {
public:
  void addValue(int speed); // 添加一笔新数据
  double averageSoFar() const; // 返回平均速度
};
