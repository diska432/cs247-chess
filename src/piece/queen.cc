#include "queen.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Queen::Queen(char team) : Piece('q', team) {};

vector<Position> Queen::getAllMoves(Chessboard &cb, Position p) {
  vector<Position> res;
  Position temp{0, 0};
  res.push_back(temp);
  return res;
}
