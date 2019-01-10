#include <tr1/memory>

class Mutex {
};

// -----Demo 1.-----
void lock(Mutex* pm) {} // 锁定pm所指的互斥器
void unlock(Mutex *pm){}; // 将互斥器解除锁定

class Lock {
public:
  explicit Lock(Mutex* pm) : mutexPtr(pm) {
    lock(mutexPtr); // 获得资源
  }
  ~Lock() {
    unlock(mutexPtr); // 释放资源
  }

private:
  Mutex *mutexPtr;
};

// -----Demo 2.-----
class Lock2 {
public:
  explicit Lock2(Mutex* pm) : mutexPtr(pm, unlock) { // 以某个Mutex初始化shared_ptr，并以unlock函数为删除器
    lock(mutexPtr.get()); // 获得资源
  }

private:
  std::tr1::shared_ptr<Mutex> mutexPtr; // 使用shared_ptr替换raw pointer
};
