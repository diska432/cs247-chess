#include "king.h"
#include "piece.h"
#include "../position.h"

using namespace std;

King::King(char team) : Piece('k', team) {};

vector<Position> King::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  vector<Position> res;

  if (!cb->positionInRange(p)) {
    throw std::out_of_range("King::getAllMoves: position out of range");
  }
  shared_ptr<Piece> piece = cb->getSquare(p);

  if (!piece) {
    return res;
  }

  char team = piece->getTeam();

  vector<Position> dirs{
    Position{1, 0}, Position{1, 1}, Position{0, 1}, Position{-1, 1},
    Position{-1, 0}, Position{-1, -1}, Position{0, -1}, Position{1, -1}
  };
  
  for (auto &pr : dirs) {
    Position temp = p + pr;
    if (cb->positionInRange(temp)) {
      shared_ptr<Piece> candidate = cb->getSquare(temp);
      if (candidate == nullptr || (candidate->getTeam() != team)) {
        res.push_back(temp);
      }
    }
  }

  return res;
}
