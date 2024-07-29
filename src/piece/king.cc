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

  // Castling :)
  if (!cb->getSquare(p)->getMoved()) {
    // if it hasn't moved
    int row = (team == 'w') ? 0 : 7;
    Position kingSideLoc = Position{row, 7};
    Position queenSideLoc = Position{row, 0};

    shared_ptr<Piece> kingSideRook = cb->getSquare(kingSideLoc);
    shared_ptr<Piece> queenSideRook = cb->getSquare(queenSideLoc);
    bool canCastle = true;
    
    if (kingSideRook && !kingSideRook->getMoved() && kingSideRook->getSymbol() == 'r') {
      // we need to check if there are any pieces in between the king and rook
      for (int x = p.getY() + 1; x < kingSideLoc.getY(); x++) {
        Position temp{row, x};
        if (cb->getSquare(temp) != nullptr) {
          canCastle = false;
          break;
        }
      }
      if (canCastle) {
        // Position kingSideCastle = Position{row, p.getX() + 2};
        Position kingSideCastle = Position{row, p.getY() + 2};
        res.push_back(kingSideCastle);
      }
    }

    canCastle = true;

    if (queenSideRook && !queenSideRook->getMoved() && queenSideRook->getSymbol() == 'r') {
      // we need to check if there are any pieces in between the king and rook
      for (int x = p.getY() - 1; x > 0; x--) {
        Position temp{row, x};
        if (cb->getSquare(temp) != nullptr) {
          canCastle = false;
          break;
        }
      }
      if (canCastle) {
        // Position kingSideCastle = Position{row, p.getX() - 2};
        Position kingSideCastle = Position{row, p.getY() - 2};
        res.push_back(kingSideCastle);
      }
    }
  }
  // cout << "King ";

  // for (auto &x : res) {
  //   cout << x << " ";
  // }

  return res;
}
