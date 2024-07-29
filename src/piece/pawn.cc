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
  if(cb->getSquare(p)->getTeam() == 'w') {
    //if position in front of the pawn is not empty
    Position squareInFront = Position{p.getX() + 1, p.getY()};
    if(p.getX() + 1 < 8 && cb->getSquare(squareInFront)) {
        blocked = true;
    } else {
        res.push_back(squareInFront);
    }
    //if pawn did not move yet we check for moving 2 squares
    Position squareTwoBlocks = Position{p.getX() + 2, p.getY()};
    if(!blocked && p.getX() == 1 && !cb->getSquare(squareTwoBlocks)) {
        res.push_back(squareTwoBlocks);
    }
    //check for capture
    if(p.getX() + 1 < 8 && p.getY() + 1 < 8 && p.getY() -1 >= 0) {
        Position caputureLeftPiece = Position{p.getX() + 1, p.getY() - 1};
        Position caputureRightPiece = Position{p.getX() + 1, p.getY() + 1};
        if(cb->getSquare(caputureLeftPiece) && cb->getSquare(caputureLeftPiece)->getTeam() == 'b') {
            res.push_back(caputureLeftPiece);
        } 
        if(cb->getSquare(caputureRightPiece) && cb->getSquare(caputureRightPiece)->getTeam() == 'b') {
            res.push_back(caputureRightPiece);
        } 
    }
  } else {
    //if position in front of the pawn is not empty
    Position squareInFront = Position{p.getX() - 1, p.getY()};

    if(p.getX() - 1 >= 0  && cb->getSquare(squareInFront)) {
        blocked = true;
    } else {
        res.push_back(squareInFront);
    }
    //if pawn did not move yet we check for moving 2 squares
    Position squareTwoBlocks = Position{p.getX() - 2, p.getY()};
    if(!blocked && p.getX() == 6 && !cb->getSquare(squareTwoBlocks)) {
        res.push_back(squareTwoBlocks);
    }
    //check for capture
    Position caputureLeftPiece = Position{p.getX() - 1, p.getY() - 1};
    Position caputureRightPiece = Position{p.getX() - 1, p.getY() + 1};
    if(p.getX() - 1 >= 0 && p.getY() + 1 < 8 && p.getY() -1 >= 0) {
        if(cb->getSquare(caputureLeftPiece) && cb->getSquare(caputureLeftPiece)->getTeam() == 'w') {
            res.push_back(caputureLeftPiece);
        } 
        if(cb->getSquare(caputureRightPiece) && cb->getSquare(caputureRightPiece)->getTeam() == 'w') {
            res.push_back(caputureRightPiece);
        } 
    }
  }
  // en passant yet to be implemented

  return res;
}
