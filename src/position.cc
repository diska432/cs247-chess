#include "position.h"
#include <string>

using namespace std;

Position::Position() : x(-1), y(-1) {};

Position::Position(int x, int y) : x(x), y(y) {};

Position::Position(string c) : x(c[1]-'1'), y(c[0]-'a') {};

int Position::getX() const { return x; };

int Position::getY() const { return y; };

bool Position::operator==(const Position& rhs) const {
  return x == rhs.getX() && y == rhs.getY();
}
