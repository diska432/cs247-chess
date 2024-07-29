#include "knight.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Knight::Knight(char team) : Piece('n', team) {};

vector<Position> Knight::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  if (!cb->positionInRange(p)) {
    throw std::out_of_range("Rook::getAllMoves: position out of range");
  }
  shared_ptr<Piece> piece = cb->getSquare(p);
  vector<Position> res;

  vector<Position> dirs{
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