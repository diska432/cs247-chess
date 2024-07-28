#include "bishop.h";
#include "piece.h"
#include "../position.h"

using namespace std;

Bishop::Bishop(char team) : Piece('b', team) {};

vector<Position> Bishop::getAllMoves(Chessboard &cb, Position p) {
  vector<Position> res;
  Position temp{0, 0};
  res.push_back(temp);
  return res;
}

