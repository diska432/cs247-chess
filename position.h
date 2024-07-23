#ifndef POSITION_H
#define POSITION_H
#include <string>

class Position {
  int x;
  int y;
  std::string coordinate;

  public:
    Position(int x, int y);
    Position(std::string coordinate);
};

#endif
