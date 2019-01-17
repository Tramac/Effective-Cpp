#include <sstream>
#include <tr1/memory>

class Mutex {
};

void lock(const Mutex* mutex) {}

void unlock(const Mutex* mutex) {}

class Lock {
public:
  explicit Lock(Mutex* pm) : mutexPtr(pm) {
    lock(mutexPtr);
  }
  ~Lock() {
    unlock(mutexPtr);
  }

private:
  Mutex *mutexPtr;
};

class Image {
public:
  Image(std::istream& i) : img(i) {}

private:
  std::istream &img;
};

class PrettyMenu {
public:
  void changeBackground(std::istream &imgSrc); // 改变背景图像

private:
  Mutex mutex; // 互斥器
  // Image *bgImage; // 当前的背景图像
  std::tr1::shared_ptr<Image> bgImage;
  int imageChanges; // 背景图像被改变的次数
};

// -----Demo 1.没有异常安全性-----
// void PrettyMenu::changeBackground(std::istream& imgSrc) {
//   lock(&mutex); // 取得互斥器
//   delete bgImage; // 摆脱旧的背景图像
//   ++imageChanges; // 修改图像变更次数
//   bgImage = new Image(imgSrc); // 安装新的背景图像
//   unlock(&mutex); // 释放互斥器
// }

// -----Demo 2.保证异常安全性-----
// void PrettyMenu::changeBackground(std::istream& imgSrc) {
//   Lock ml(&mutex); // 获得互斥器并确保它稍后被释放
//   delete bgImage;
//   ++imageChanges;
//   bgImage = new Image(imgSrc);
// }

// -----Demo 3.基本的异常安全保证-----
void PrettyMenu::changeBackground(std::istream& imgSrc) {
  Lock ml(&mutex);
  bgImage.reset(new Image(imgSrc)); // 以“new Image"的执行结果设定bgImage内部指针
  ++imageChanges;
}

// -----Demo 4.pimpl idiom强烈保证-----
struct PMImpl {
  std::tr1::shared_ptr<Image> bgImage;
  int imageChanges;
};

class PrettyMenu2 {
public:
  void changeBackground(std::istream &imgSrc); // 改变背景图像

private:
  Mutex mutex;
  std::tr1::shared_ptr<PMImpl> pImpl;
};

void PrettyMenu2::changeBackground(std::istream& imgSrc) {
  using std::swap;
  Lock ml(&mutex); // 获得mutex的副本数据
  std::tr1::shared_ptr<PMImpl> pNew(new PMImpl(*pImpl));
  pNew->bgImage.reset(new Image(imgSrc)); // 修改副本
  ++pNew->imageChanges;
  swap(pImpl, pNew); // 置换数据，释放mutex
}
