#include "pawn.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Pawn::Pawn(char team) : Piece('p', team) {};

vector<Position> Pawn::getAllMoves(Chessboard &cb) {
  vector<Position> res;
  Position p{0, 0};
  res.push_back(p);
  return res;
}
