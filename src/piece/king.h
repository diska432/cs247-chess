#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece {
  public:
    King(char team);
    std::vector<Position>getAllMoves(Chessboard &cb, Position p) override;
};

#endif
