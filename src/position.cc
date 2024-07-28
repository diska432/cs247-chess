#include "position.h"
#include <string>

using namespace std;

Position::Position(int x, int y) : x(x), y(y) {}

int Position::getX() const { return x; }

int Position::getY() const { return y; }

