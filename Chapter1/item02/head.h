#include <iostream>
#include <string>

// Demo 3.
const char *const authorName_c = "Scott Meyers";
// Demo 4.
const std::string authorName_s("Scott Meyers");
// Demo 5.
class GamePlayer {
    private:
      static const int NumTurns = 5;
      int scores[NumTurns];
    
    public:
      GamePlayer() {
          std::cout << "NumTurns: " << NumTurns << std::endl;
      }
};

class CostEstimate {
    private:
      static const double FudgeFactor;
};

class GamePlayer_e {
    private:
      enum { NumTurns = 5 };
      int scores[NumTurns];
    
    public:
      GamePlayer_e() {
          std::cout << "NumTurns: " << NumTurns << std::endl;
      }
};
