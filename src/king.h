#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece {
  public:
    King(char symbol, char color, Position pos);
    vector<Position>getAllMoves(Chessboard &cb) override;
};

#endif
