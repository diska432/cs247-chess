#ifndef LEVEL1_H
#define LEVEL1_H
#include <string>
#include "computer.h"

class Level1 : public Computer {
  public:
    virtual std::pair<Position, Position> getMove() override;
    Level1();
};

#endif
