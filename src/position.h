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

    bool operator==(const Position& rhs) const;
    Position operator+(const Position& p) const;
    Position operator-(const Position& p) const;

    friend std::ostream& operator<<(std::ostream& out, const Position& p);
    std::string toString() const;
};

#endif
