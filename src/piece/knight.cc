#include "knight.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Knight::Knight(char team) : Piece('n', team) {};

vector<Position> Knight::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  vector<Position> res;
  res.push_back(Position{"f6"});
  return res;

}
