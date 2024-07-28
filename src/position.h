#ifndef POSITION_H
#define POSITION_H
#include <string>
#include <iostream>

class Position {
  int x;
  int y;

  public:
    Position();
    Position(int x, int y);
    Position(std::string c);

    int getX() const;
    int getY() const;

    std::string toString() const;

    // operator overloads
    // print for debugging purposes
    friend std::ostream& operator<<(std::ostream& out, const Position& p);
};

#endif
