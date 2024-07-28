#include "level1.h"
#include <cstdlib> 
#include <iostream>
#include <ctime>

Level1::Level1() {
  isHuman = false;
}

Level1::Level1(std::shared_ptr<Chessboard> chess) {
  isHuman = false;
  chessboard = chess;
}

std::pair<Position, Position> Level1::getMove() {
  std::cout << "Computer is making a move" << std::endl;
  Position p = Position{"g8"};
  // srand(time(0));
  // auto test = ;
  std::vector<Position> moves = chessboard->getSquare(p)->getAllMoves(chessboard, p);
  // int random_variable = rand() % 100 + 1;

  return std::make_pair(Position{"g8"}, Position{"g5"});
}

