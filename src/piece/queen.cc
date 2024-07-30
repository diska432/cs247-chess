#include "queen.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Queen::Queen(char team) : Piece('q', team) {};

vector<Position> Queen::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  if (!cb->positionInRange(p)) {
    throw std::out_of_range("Queen::getAllMoves: position out of range");
  }
  shared_ptr<Piece> piece = cb->getSquare(p);
  vector<Position> res;

  vector<Position> dirs{
    Position{1, 0}, Position{-1, 0}, Position{0, 1}, Position{0, -1},
    Position{1, 1}, Position{-1, 1}, Position{1, -1}, Position{-1, -1}
  };

  for (auto &pr : dirs) {
    Position temp = p + pr;
    while (cb->positionInRange(temp)) {
      shared_ptr<Piece> candidate = cb->getSquare(temp);
      if (candidate != nullptr) {
        // we are at a wall anymore,
        // let's choose whether or not to add it
        if (candidate->getTeam() != team) {
          res.push_back(temp);
        }
        break;
      }
      res.push_back(temp);
      temp = temp + pr;
    }
  }

  return res;
}