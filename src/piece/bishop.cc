#include "bishop.h";
#include "piece.h"
#include "../position.h"

using namespace std;

Bishop::Bishop(char team) : Piece('b', team) {};

vector<Position> Bishop::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  if (!cb->positionInRange(p)) {
    throw std::out_of_range("Rook::getAllMoves: position out of range");
  }
  shared_ptr<Piece> piece = cb->getSquare(p);
  char team = piece->getTeam();
  vector<Position> res;

  vector<Position> dirs{Position{1, 1}, Position{1, -1}, Position{-1, 1}, Position{-1, -1}};

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

  for (auto& p : res) {
    cout << "Bishop validation moves: " << p << " ";
  }

  return res;
}

