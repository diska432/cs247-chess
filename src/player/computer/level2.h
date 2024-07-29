#ifndef LEVEL2_H
#define LEVEL2_H
#include <string>
#include "computer.h"

class Level2 : public Computer {
  public:
    Level2(std::shared_ptr<Chessboard>, char color);
    std::pair<Position, Position> getMove() override;
};

#endif