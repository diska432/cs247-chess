#include "bishop.h";
#include "piece.h"
#include "../position.h"

using namespace std;

Bishop::Bishop(char team) : Piece('b', team) {};

vector<Position> Bishop::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  vector<Position> res;
  for(int i = 0; i < 8; i++) {
    int newX = p.getX() - i;
    int newY = p.getY() + i;
    //check for bounds
    if(newX < 0 || newY > 7) break;
    //if position not empty
    Position temp = Position{newX, newY};
    if(cb->getSquare(temp) ) {
        //if same team then can't move
        if(cb->getSquare(temp)->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back({newX, newY});
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back({newX, newY});
    }
  }

  for(int i = 0; i < 8; i++) {
    int newX = p.getX() + i;
    int newY = p.getY() + i;
    //check for bounds
    if(newX < 0 || newY > 7) break;
    //if position not empty
    Position temp = Position{newX, newY};
    if(cb->getSquare(temp) ) {
        //if same team then can't move
        if(cb->getSquare(temp)->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back({newX, newY});
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back({newX, newY});
    }
  }

  for(int i = 0; i < 8; i++) {
    int newX = p.getX() + i;
    int newY = p.getY() - i;
    //check for bounds
    if(newX < 0 || newY > 7) break;
    //if position not empty
    Position temp = Position{newX, newY};
    if(cb->getSquare(temp) ) {
        //if same team then can't move
        if(cb->getSquare(temp)->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back({newX, newY});
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back({newX, newY});
    }
  }

  for(int i = 0; i < 8; i++) {
    int newX = p.getX() - i;
    int newY = p.getY() - i;
    //check for bounds
    if(newX < 0 || newY > 7) break;
    //if position not empty
    Position temp = Position{newX, newY};
    if(cb->getSquare(temp) ) {
        //if same team then can't move
        if(cb->getSquare(temp)->getTeam() == this->getTeam()) {
            break;
        } else {
            //if different teams can capture but can't move to squares after the piece
            res.push_back({newX, newY});
            break;
        }
    } else {
        //if empty square then valid move
        res.push_back({newX, newY});
    }
  }
  return res;
}

