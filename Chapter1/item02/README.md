# 条款02：尽量以const,enum,inline替换 #define
 -------------------
 
 **1.#define存在的问题。**<br>
 #define不被视为语言的一部分。例如：
 ```
 #define ASPECT_RATIO 1.653
 ```
 记号名称ASPECT_RATIO也许从未被编译器看见，也许在编译器开始处理源码之前就被预处理器移走了，从而导致记号名称ASPECT_RATIO有可能没进入记号表。于是当你运用此常量但获得一个编译错误信息时，可能会带来困惑。
 
 **2.用const替换#define。**<br>
 ```
 const double AspectRatio = 1.653;
 ```
 作为一个常量，AspectRatio肯定会被编译器看到，当然就会进入记号表内。此外对浮点常量而言，使用常量可能比用#define导致较小量的代码，因为预处理器“盲目地将宏名称ASPECT_RATIO替换为1.653“可能导致目标码出现多份1.653。
 
 **3.两种特殊情况。**<br>
 * 在头文件中定义常量指针时有必要将指针声明为const，所以必须写const两次
 ```
 const char* const autorName = "Scott Meyers";
  ```
  * 对于class专属常量，为了常量的作用于限制于class内，必须让它成为class的一个成员；而为确保此常量至多只有一份实体，你必须让它成为一个static成员。
  
  **4.我们无法利用#define创建一个class专属常量，因为#define并不重视作用域，同时也不能够提供任何封装性，也就是说没有所谓private #define这样的东西。**<br>
  
  **5.enum, const, #define三者的区别。**
  enum hack的行为更加像#define而不像const，比如取一个const的地址是合法的，但取一个enum的地址就不合法，而取一个#define的地址通常也不合法。
  
  ## 请记住：
  * 对于单纯常量，最好以const对象或enum替换#define。
  * 对于形似函数的宏，最好改用inline函数替换#define。
