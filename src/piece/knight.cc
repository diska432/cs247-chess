#include "knight.h"
#include "piece.h"
#include "../position.h"

using namespace std;

Knight::Knight(char team) : Piece('n', team) {};

vector<Position> Knight::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  vector<Position> res;

if(p.getX() + 2 < 8 ) {
    //check if square is empty or there is an opposing piece
    if(p.getY() + 1 < 8 && (!cb.getSquare({p.getX() + 2, p.getY() + 1}) || (cb.getSquare({p.getX() + 2, p.getY() + 1}) && 
    cb.getSquare({p.getX() + 2, p.getY() + 1})->getTeam() != cb.getSquare({p.getX(), p.getY()})->getTeam()))) {
        res.push_back({p.getX() + 2, p.getY() + 1});
    }
    //check if square is empty or there is an opposing piece
    if(p.getY() - 1 >= 0 && (!cb.getSquare({p.getX() + 2, p.getY() - 1}) || (cb.getSquare({p.getX() + 2, p.getY() - 1}) && cb.getSquare({p.getX() + 2, p.getY() - 1})->getTeam() != cb.getSquare({p.getX(), p.getY()})->getTeam()))) {
        res.push_back({p.getX() + 2, p.getY() - 1});
    }
} 
if(p.getX() - 2 >= 0) {
    //check if square is empty or there is an opposing piece
    if(p.getY() + 1 < 8 && (!cb.getSquare({p.getX() - 2, p.getY() + 1}) || (cb.getSquare({p.getX() - 2, p.getY() + 1}) && cb.getSquare({p.getX() - 2, p.getY() + 1}) ->getTeam() != cb.getSquare({p.getX(), p.getY()})->getTeam()))) {
        res.push_back({p.getX() - 2, p.getY() + 1});
    }
    //check if square is empty or there is an opposing piece
    if(p.getY() - 1 >= 0 && (!cb.getSquare({p.getX() - 2, p.getY() - 1}) || (cb.getSquare({p.getX() - 2, p.getY() - 1}) && cb.getSquare({p.getX() - 2, p.getY() - 1}) ->getTeam() != cb.getSquare({p.getX(), p.getY()})->getTeam()))) {
        res.push_back({p.getX() - 2, p.getY() - 1});
    }
}
if(p.getY() + 2 < 8) {
    //check if square is empty or there is an opposing piece
    if(p.getX() + 1 < 8 && (!cb.getSquare({p.getX() + 1, p.getY() + 2}) || (cb.getSquare({p.getX() + 1, p.getY() + 2}) && cb.getSquare({p.getX() + 1, p.getY() + 2}) ->getTeam() != cb.getSquare({p.getX(), p.getY()})->getTeam()))) {
        res.push_back({p.getX() + 1, p.getY() + 2});
    }
    //check if square is empty or there is an opposing piece
    if(p.getX() - 1 >= 0 && (!cb.getSquare({p.getX() - 1, p.getY() + 2}) || (cb.getSquare({p.getX() - 1, p.getY() + 2}) && cb.getSquare({p.getX() - 1, p.getY() + 2}) ->getTeam() != cb.getSquare({p.getX(), p.getY()})->getTeam()))) {
        res.push_back({p.getX() - 1, p.getY() + 2});
    }
}
if(p.getY() - 2 >= 0) {
    //check if square is empty or there is an opposing piece
    if(p.getX() + 1 < 8 && (!cb.getSquare({p.getX() + 1, p.getY() - 2}) || (cb.getSquare({p.getX() + 1, p.getY() - 2}) && cb.getSquare({p.getX() + 1, p.getY() - 2}) ->getTeam() != cb.getSquare({p.getX(), p.getY()})->getTeam()))) {
        res.push_back({p.getX() + 1, p.getY() - 2});
    }
    //check if square is empty or there is an opposing piece
    if(p.getX() - 1 >= 0 && (!cb.getSquare({p.getX() - 1, p.getY() - 2}) || (cb.getSquare({p.getX() - 1, p.getY() - 2}) && cb.getSquare({p.getX() - 1, p.getY() - 2}) ->getTeam() != cb.getSquare({p.getX(), p.getY()})->getTeam()))) {
        res.push_back({p.getX() - 1, p.getY() - 2});
    }
}


//   res.push_back(Position{"f6"});
//   res.push_back(Position{"h6"});


  return res;
}
