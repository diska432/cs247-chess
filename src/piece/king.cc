#include "king.h"
#include "piece.h"
#include "../position.h"

using namespace std;

King::King(char team) : Piece('k', team) {};

vector<Position> King::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  vector<Position> res;

//   Position temp{0, 0};
//   res.push_back(temp);

  if (!cb->positionInRange(p)) {
    throw std::out_of_range("King::getAllMoves: position out of range");
  }
  shared_ptr<Piece> piece = cb->getSquare(p);
  char team = piece->getTeam();

  vector<Position> dirs{
    Position{1, 0}, Position{1, 1}, Position{0, 1}, Position{-1, 1},
    Position{-1, 0}, Position{-1, -1}, Position{0, -1}, Position{1, -1}
  };
  
  for (auto &pr : dirs) {
    Position temp = p + pr;

    if (cb->positionInRange(temp)) {
      shared_ptr<Piece> candidate = cb->getSquare(temp);
      //check if the square is threatened by enemy piece
      //can only move if not threatened
      // only accept position if it's empty or 
      // it's a capture on a piece
      if((candidate == nullptr || candidate->getTeam() != team) && !cb->isSquareUnderAttack(temp, team)) {
        res.push_back(temp);
      }
    }
  }

  cout << "King validation moves: ";

  for (auto& p : res) {
    cout << p << " ";
  }
  

  // Position temp{0, 0};
  // res.push_back(temp);

  return res;
}
