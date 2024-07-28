#include "king.h"
#include "piece.h"
#include "../position.h"

using namespace std;

King::King(char team) : Piece('k', team) {};

vector<Position> King::getAllMoves(Chessboard &cb) {
  vector<Position> res;
  Position p{0, 0};
  res.push_back(p);
  return res;
}
