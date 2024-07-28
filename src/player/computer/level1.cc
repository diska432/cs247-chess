#include "level1.h"

Level1::Level1() {
  isHuman = false;
}

std::pair<Position, Position> Level1::getMove() {
  std::cout << "Computer is making a move" << std::endl;
  return std::make_pair(Position{"e7"}, Position{"e6"});
}

