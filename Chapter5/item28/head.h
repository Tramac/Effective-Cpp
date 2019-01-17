#include <tr1/memory>

class Point { // 该class用来表述“点”
public:
  Point() {}
  Point(int xx, int yy) : x(xx), y(yy) {}
  void setX(int newVal) { x = newVal; }
  void setY(int newVal) { y = newVal; }

private:
  int x, y;
};

struct RectData { // 矩形
  Point ulhc; // 左上角
  Point lrhc; // 右下角
};

// -----Demo 1.-----
class Rectangle {
public:
  Point &upperLeft() const { return pData->ulhc; }
  Point &lowerRight() const { return pData->lrhc; }

private:
  std::tr1::shared_ptr<RectData> pData;
};

// -----Demo 2.-----
class Rectangle2 {
public:
  const Point &upperLeft() const { return pData->ulhc; }
  const Point &lowerRight() const { return pData->lrhc; }

private:
  std::tr1::shared_ptr<RectData> pData;
};

// -----Demo 3.-----
class GUIObject {
};
