#ifndef STUDIO_H
#define STUDIO_H
#include <iostream>
#include "position.h"

class Move {
  protected:
    Position p1;
    Position p2;
  public:
    Move(Position p1, Position p2) : p1(p1), p2(p2) {};
};

#endif
