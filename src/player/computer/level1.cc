#include "level1.h"

Level1::Level1() {
  isHuman = false;
}

std::pair<Position, Position> Level1::getMove() {
  std::string f, t;
  std::cin >> f >> t;
  return std::make_pair(Position{f}, Position{t});
}

