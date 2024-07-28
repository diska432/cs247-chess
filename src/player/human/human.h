#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include "../player.h"

class Human : public Player {
  public:
    std::pair<Position, Position> getMove() override;
    Human();
};

#endif
