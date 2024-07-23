#ifndef PIECE_H
#define PIECE_H
#include "../position.h"
#include "../chessboard.h"

class Piece {
  char symbol;
  char color;
  Position pos;

  public:
    Piece(char symbol, char color, Position pos);
    virtual vector<Position>getAllMoves(Chessboard &cb) = 0;
};

#endif
