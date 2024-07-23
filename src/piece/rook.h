#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook : public Piece {
  public:
    Rook(char symbol, char color, Position pos);
    vector<Position>getAllMoves(Chessboard &cb) override;
};

#endif
