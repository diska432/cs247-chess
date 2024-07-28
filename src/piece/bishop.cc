#include "bishop.h";
#include "piece.h"
#include "../position.h"

using namespace std;

Bishop::Bishop(char team) : Piece('b', team) {};

vector<Position> Bishop::getAllMoves(Chessboard &cb) {
  vector<Position> res;
  Position p{0, 0};
  res.push_back(p);
  return res;
}

