#include "position.h"
#include <string>
#include <iostream>

using namespace std;

Position::Position() : x(-1), y(-1) {};

Position::Position(int x, int y) : x(x), y(y) {};

Position::Position(string c) : x(c[1]-'1'), y(c[0]-'a') {};

int Position::getX() const { return x; };

int Position::getY() const { return y; };

string Position::toString() const {
  char l = 'a' + y;
  string res = l + to_string(x+1);
  return res;
}

bool Position::operator==(const Position& rhs) const {
  return x == rhs.getX() && y == rhs.getY();
}

Position Position::operator+(const Position& p) const {
  return Position{x + p.getX(), y + p.getY()};
}

Position Position::operator-(const Position& p) const {
  return Position{x - p.getX(), y - p.getY()};
}

ostream& operator<<(ostream& out, const Position& p) {
  out << p.toString();
  return out;
}

bool Position::operator<(const Position& other) const {
    if (x == other.getX()) return y < other.getY();
    return x < other.getX();
}

