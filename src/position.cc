#include "position.h"
#include <string>

using namespace std;

Position::Position(int x, int y) : x(x), y(y) {};

Position::Position(string c) : y(c[0]-'a'), x(c[1]-'1') {};

int Position::getX() const { return x; };

int Position::getY() const { return y; };

