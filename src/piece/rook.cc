#include "rook.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Rook::Rook(char team) : Piece('r', team) {};

vector<Position> Rook::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  vector<Position> res;
  //check for everything to the left of rook in case rook is not on the edge
  for(int i = p.getY(); i >= 0; --i) {
    Position newPosition = Position{p.getX(), i};
    //check if position is not empty
    if(cb->getSquare(newPosition) ) {  
        //if same team then can't move
        if(cb->getSquare(newPosition)->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back({newPosition});
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back(newPosition);
    }
  }
  //check for everything to the right of rook in case rook is not on the edge
  for(int i = p.getY(); i < 8; ++i) {
    Position newPosition = Position{p.getX(), i};
    //check if position is not empty
    if(cb->getSquare(newPosition) ) {
        //if same team then can't move
        if(cb->getSquare(newPosition)->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back(newPosition);
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back(newPosition);
    }
  }
  //check for everything up of rook in case rook is not on the edge
  for(int i = p.getX(); i < 8; ++i) {
    Position newPosition = Position{p.getX(), i};
    //check if position is not empty
    if(cb->getSquare(newPosition) ) {
        //if same team then can't move
        if(cb->getSquare(newPosition)->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back({newPosition});
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back({i, p.getY()});
    }
  }
  //check for everything down of rook in case rook is not on the edge
  for(int i = p.getX(); i >= 0; --i) {
    Position newPosition = Position{p.getX(), i};
    //check if position is not empty
    if(cb->getSquare(newPosition) ) {
        //if same team then can't move
        if(cb->getSquare(newPosition)->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back(newPosition);
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back(newPosition);
    }
  }
  return res;
}
