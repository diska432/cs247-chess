#include "rook.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Rook::Rook(char team) : Piece('r', team) {};

vector<Position> Rook::getAllMoves(Chessboard &cb, Position p) {
  vector<Position> res;
  Position temp{0, 0};
  res.push_back(temp);
  return res;
}
