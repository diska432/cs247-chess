#ifndef LEVEL1_H
#define LEVEL1_H
#include <string>
#include "computer.h"

class Level1 : public Computer {
  public:
    Level1(std::shared_ptr<Chessboard> chessboard);
    std::pair<Position, Position> getMove() override;
};

#endif
