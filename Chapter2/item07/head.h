#include <string>

// -----Demo 1.-----
class TimeKeeper {
public:
    TimeKeeper();
    ~TimeKeeper();
};

class AtomicClock: public TimeKeeper {};
class WaterClock: public TimeKeeper {};
class WristWatch: public TimeKeeper {};

// -----Demo 2.-----
class TimeKeeper2 {
public:
  TimeKeeper2();
  virtual ~TimeKeeper2();
};

// -----Demo 3.-----
class Point {
public:
  Point(int xCoord, int yCoord);
  ~Point();

private:
  int x, y;
};

// -----Demo 4.-----
class SpecialString: public std::string {
};

// -----Demo 5.-----
class AWOV {
public:
  virtual ~AWOV() = 0; // 声明纯虚析构函数
};
