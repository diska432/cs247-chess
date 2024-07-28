#include "rook.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Rook::Rook(char team) : Piece('r', team) {};

vector<Position> Rook::getAllMoves(Chessboard &cb) {
  vector<Position> res;
  Position p{0, 0};
  res.push_back(p);
  return res;
}
