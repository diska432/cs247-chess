#include "position.h"
#include <string>
#include <iostream>

using namespace std;

Position::Position() : x(-1), y(-1) {};

Position::Position(int x, int y) : x(x), y(y) {};

Position::Position(string c) : x(c[1]-'1'), y(c[0]-'a') {
  cout << "Created x: " << x << ", y: " << y << " | " << toString() << "\n";
  // cout << toString
};

int Position::getX() const { return x; };

int Position::getY() const { return y; };

std::string Position::toString() const {
  char l = 'a' + x;
  string res = l + to_string(y+1);
  return res;
}

ostream& operator<<(ostream& out, const Position& p) {
  out << "X: " << p.getX() << ", Y: " << p.getY() << " | ";
  out << p.toString();
  return out;
}
