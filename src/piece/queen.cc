#include "queen.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Queen::Queen(char team) : Piece('q', team) {};

vector<Position> Queen::getAllMoves(Chessboard &cb) {
  vector<Position> res;
  Position p{0, 0};
  res.push_back(p);
  return res;
}
