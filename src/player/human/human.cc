#include "human.h"

Human::Human() {
  isHuman = true;
}

std::pair<Position, Position> Human::getMove() {
  std::string f, t;
  std::cin >> f >> t;
  return std::make_pair(Position{f}, Position{t});
}