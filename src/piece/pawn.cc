#include "pawn.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Pawn::Pawn(char team) : Piece('p', team) {};

vector<Position> Pawn::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  vector<Position> res;
//   Position temp{0, 0};
//   res.push_back(temp);
//   return res;
  bool blocked = false;
  if(cb.getSquare({p.getX(), p.getY()})->getTeam() == 'w') {
    //if position in front of the pawn is not empty
    if(p.getX() + 1 < 8 && cb.getSquare({p.getX() + 1, p.getY()})) {
        blocked = true;
    } else {
        res.push_back({p.getX() + 1, p.getY()});
    }
    //if pawn did not move yet we check for moving 2 squares
    if(!blocked && p.getX() == 1 && !cb.getSquare({p.getX() + 2, p.getY()})) {
        res.push_back({p.getX() + 2, p.getY()});
    }
    //check for capture
    if(p.getX() + 1 < 8 && p.getY() + 1 < 8 && p.getY() -1 >= 0) {
        if(cb.getSquare({p.getX() + 1, p.getY() + 1}) && cb.getSquare({p.getX() + 1, p.getY() + 1})->getTeam() == 'b') {
            res.push_back({p.getX() + 1, p.getY() + 1});
        } 
        if(cb.getSquare({p.getX() + 1, p.getY() - 1}) && cb.getSquare({p.getX() + 1, p.getY() - 1})->getTeam() == 'b') {
            res.push_back({p.getX() + 1, p.getY() - 1});
        } 
    }
  } else {
    //if position in front of the pawn is not empty
    if(p.getX() - 1 >= 0  && cb.getSquare({p.getX() - 1, p.getY()})) {
        blocked = true;
    } else {
        res.push_back({p.getX() - 1, p.getY()});
    }
    //if pawn did not move yet we check for moving 2 squares
    if(!blocked && p.getX() == 6 && !cb.getSquare({p.getX() - 2, p.getY()})) {
        res.push_back({p.getX() - 2, p.getY()});
    }
    //check for capture
    if(p.getX() - 1 >= 0 && p.getY() + 1 < 8 && p.getY() -1 >= 0) {
        if(cb.getSquare({p.getX() - 1, p.getY() + 1}) && cb.getSquare({p.getX() - 1, p.getY() + 1})->getTeam() == 'w') {
            res.push_back({p.getX() - 1, p.getY() + 1});
        } 
        if(cb.getSquare({p.getX() - 1, p.getY() - 1}) && cb.getSquare({p.getX() - 1, p.getY() - 1})->getTeam() == 'w') {
            res.push_back({p.getX() - 1, p.getY() - 1});
        } 
    }
  }

  // en passant yet to be implemented

  return res;
}
