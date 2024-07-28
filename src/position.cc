#include "position.h"
#include <string>

using namespace std;

Position::Position() : x(-1), y(-1) {};

Position::Position(int x, int y) : x(x), y(y) {};

Position::Position(string c) : x('8'-c[1]), y(c[0]-'a') {};

int Position::getX() const { return x; };

int Position::getY() const { return y; };

