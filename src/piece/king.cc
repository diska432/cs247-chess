#include "king.h"
#include "piece.h"
#include "../position.h"

using namespace std;

King::King(char team) : Piece('k', team) {};

vector<Position> King::getAllMoves(Chessboard &cb, Position p) {
  vector<Position> res;
  Position temp{0, 0};
  res.push_back(temp);
  return res;
}
