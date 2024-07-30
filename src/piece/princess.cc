#include "princess.h";
#include "piece.h"
#include "../position.h"

using namespace std;

Princess::Princess(char team) : Piece('f', team) {};

vector<Position> Princess::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  if (!cb->positionInRange(p)) {
    throw std::out_of_range("Princess::getAllMoves: position out of range");
  }
  shared_ptr<Piece> piece = cb->getSquare(p);
  vector<Position> res;

  vector<Position> dirs{Position{1, 1}, Position{1, -1}, Position{-1, 1}, Position{-1, -1}, };

  for (auto &pr : dirs) {
    Position temp = p + pr;
    while (cb->positionInRange(temp)) {
      shared_ptr<Piece> candidate = cb->getSquare(temp);
      if (candidate != nullptr) {
        // our bishop can't move past this piece anyway
        if (candidate->getTeam() != team) {
          res.push_back(temp);
        }
        break;
      }
      res.push_back(temp);
      temp = temp + pr;
    }
  }
  dirs = {
    Position{2, 1}, Position{2, -1}, Position{-2, 1}, Position{-2, -1},
    Position{1, 2}, Position{1, -2}, Position{-1, 2}, Position{-1, -2}
  };

  for (auto &pr : dirs) {
    Position temp = p + pr;
    if (cb->positionInRange(temp)) {
      shared_ptr<Piece> candidate = cb->getSquare(temp);
      if (candidate == nullptr || candidate->getTeam() != team) {
        // only accept position if it's empty or 
        // it's a capture on a piece 
        res.push_back(temp);
      }
    }
  }

  return res;
}