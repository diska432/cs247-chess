#include <vector>
#include <utility>
#include "rook.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Rook::Rook(char team) : Piece('r', team) {};

vector<Position> Rook::getAllMoves(shared_ptr<Chessboard> cb, Position p) {
  if (!cb->positionInRange(p)) {
    throw std::out_of_range("Rook::getAllMoves: position out of range");
  }
  shared_ptr<Piece> piece = cb->getSquare(p);
  char team = piece->getTeam();
  vector<Position> res;

  vector<Position> dirs{Position{1, 0}, Position{-1, 0}, Position{0, 1}, Position{0, -1}};
  
  for (auto &pr : dirs) {
    Position temp = p + pr;
    // Position temp{p.getX() + pr.first, p.getY() + pr.second};
    while (cb->positionInRange(temp)) {
      shared_ptr<Piece> candidate = cb->getSquare(temp);
      if (candidate != nullptr) {
        // our rook can't move past this piece anyway
        if (candidate->getTeam() != team) {
          res.push_back(temp);
        }
        break;
      }
      res.push_back(temp);
      temp = temp + pr;
    }
  }

  for (auto& p : res) {
    cout << "Rook validation moves: " << p << " ";
  }

  return res;
}
