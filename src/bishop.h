#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop : public Piece {
  public:
    Bishop(char symbol, char color, Position pos);
    vector<Position>getAllMoves(Chessboard &cb) override;
};

#endif
