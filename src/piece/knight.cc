#include "knight.h"
#include "piece.h"
#include "../position.h"
#include <cstdlib>

using namespace std;

Knight::Knight(char team) : Piece('n', team) {};

vector<Position> Knight::getAllMoves(std::shared_ptr<Chessboard> cb, Position p) {
  vector<Position> res;
  int dirx[] = {2, -2, 1, -1};
  int diry[] = {1, -1, 2, -2};
  for(int i = 0; i < 4; i++ ){
    for(int j = 0; j < 4; j++) {
        if(abs(dirx[i] == abs(diry[i]))) continue;
        int newX = p.getX() + dirx[i];
        int newY = p.getY() + diry[i];
        if(newX > 8 || newX < 0 || newY > 8 || newY < 0) continue; 
        Position newPosition = Position{newX, newY};
        //empty square
        if(!cb->getSquare(newPosition)) {
            res.push_back(newPosition);
        } else {
            //the square has a piece of the opposing team
            if(cb->getSquare(newPosition)->getTeam() != cb->getSquare(p)->getTeam()) {
                res.push_back(newPosition);
            }
        }
    }
  }
  return res;

}
