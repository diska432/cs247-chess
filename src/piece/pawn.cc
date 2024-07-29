#include "pawn.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Pawn::Pawn(char team) : Piece('p', team) {};

vector<Position> Pawn::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  vector<Position> res;
  Position temp{0, 0};
  res.push_back(temp);
  return res;
}
