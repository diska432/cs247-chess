#ifndef LEVEL4_H
#define LEVEL4_H
#include <string>
#include "computer.h"

class Level4 : public Computer {
  int weighOutcomes();
  public:
    Level4(std::shared_ptr<Chessboard>, char color);
    std::pair<Position, Position> getMove() override;
};

#endif