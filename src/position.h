#ifndef POSITION_H
#define POSITION_H
#include <string>

class Position {
  int x;
  int y;

  public:
    Position();
    Position(int x, int y);
    Position(std::string c);
    int getX() const;
    int getY() const;
};

#endif
