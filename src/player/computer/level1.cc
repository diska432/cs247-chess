#include "level1.h"
#include <cstdlib> 
#include <iostream>
#include <ctime>

using namespace std;

Level1::Level1(shared_ptr<Chessboard> chessboard) : Computer(chessboard) {}

pair<Position, Position> Level1::getMove() {
  Position p = Position{"g8"};
  srand(time(0));
  vector<Position> moves = chessboard->getSquare(p)->getAllMoves(chessboard, p);
  int random_variable = (rand() % moves.size());

  return make_pair(Position{"g8"}, moves[random_variable]);
}
