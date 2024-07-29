#include "rook.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Rook::Rook(char team) : Piece('r', team) {};

vector<Position> Rook::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  vector<Position> res;
/*
  //check for everything to the left of rook in case rook is not on the edge
  for(int i = p.getY(); i >= 0; --i) {
    //check if position is not empty
    if(cb.getSquare({p.getX(), i}) ) {
        //if same team then can't move
        if(cb.getSquare({p.getX(), i})->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back({p.getX(), i});
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back({p.getX(), i});
    }
  }
  //check for everything to the right of rook in case rook is not on the edge
  for(int i = p.getY(); i < 8; ++i) {
    //check if position is not empty
    if(cb.getSquare({p.getX(), i}) ) {
        //if same team then can't move
        if(cb.getSquare({p.getX(), i})->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back({p.getX(), i});
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back({p.getX(), i});
    }
  }
  //check for everything up of rook in case rook is not on the edge
  for(int i = p.getX(); i < 8; ++i) {
    //check if position is not empty
    if(cb.getSquare({i, p.getY()}) ) {
        //if same team then can't move
        if(cb.getSquare({i, p.getY()})->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back({i, p.getY()});
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back({i, p.getY()});
    }
  }
  //check for everything down of rook in case rook is not on the edge
  for(int i = p.getX(); i >= 0; --i) {
    //check if position is not empty
    if(cb.getSquare({i, p.getY()}) ) {
        //if same team then can't move
        if(cb.getSquare({i, p.getY()})->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back({i, p.getY()});
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back({i, p.getY()});
    }
  }
  */
  return res;
}
