#include "knight.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Knight::Knight(char team) : Piece('n', team) {};

vector<Position> Knight::getAllMoves(Chessboard &cb, Position p) {
  vector<Position> res;
  Position temp{0, 0};
  res.push_back(temp);
  return res;
}
