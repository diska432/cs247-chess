#ifndef LEVEL3_H
#define LEVEL3_H
#include <string>
#include "computer.h"

class Level3 : public Computer {
  int weighOutcomes();
  public:
    Level3(std::shared_ptr<Chessboard>, char color);
    std::pair<Position, Position> getMove() override;
};

#endif