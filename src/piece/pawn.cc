#include "pawn.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Pawn::Pawn(char team) : Piece('p', team) {};

vector<Position> Pawn::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  if (!cb->positionInRange(p)) {
    throw std::out_of_range("Rook::getAllMoves: position out of range");
  }
  shared_ptr<Piece> piece = cb->getSquare(p);
  vector<Position> res;

  int yVector = team == 'w' ? 1 : -1;
  vector<Position> dirs = {Position{yVector, 0}};
  // Position dir = Position{0, yVector};

  // consider an unmoved pawn that can move 2 spaces
  if (piece != nullptr && !piece->getMoved()) {
    Position forward = p + dirs[0];
    Position forwardTwice = forward + dirs[0];
    cout << forward << " | " << forwardTwice << "\n";
    if (cb->positionInRange(forwardTwice)) {
      if (cb->getSquare(forward) == nullptr && cb->getSquare(forwardTwice) == nullptr) {
        res.push_back(forwardTwice);
      }
    }
  }

  Position forward = p + dirs[0];
  if (cb->positionInRange(forward)) {
    if (cb->getSquare(forward) == nullptr) {
      res.push_back(forward);
    }
  }

  // capture move
  vector<Position> captures{Position{yVector, 1}, Position{yVector, -1}};
  for (auto &pr : captures) {
    Position temp = p + pr;
    if (cb->positionInRange(temp)) {
      shared_ptr<Piece> candidate = cb->getSquare(temp);
      if (candidate && candidate->getTeam() != team) {
        res.push_back(temp);
      }
    }
  }

  // en passante possible move
  Position right{0, 1};
  Position left{0, -1};
  if (p + right == cb->getPotentialEnPassant()) {
    res.push_back(p + Position{yVector, 1});
  }
  if (p + left == cb->getPotentialEnPassant()) {
    res.push_back(p + Position{yVector, -1});
  }


  return res;
}
