#include "knight.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Knight::Knight(char team) : Piece('n', team) {};

vector<Position> Knight::getAllMoves(Chessboard &cb) {
  vector<Position> res;
  Position p{0, 0};
  res.push_back(p);
  return res;
}
