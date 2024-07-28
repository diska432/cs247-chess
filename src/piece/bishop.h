#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop : public Piece {
  public:
    Bishop(char team);
    std::vector<Position>getAllMoves(Chessboard &cb) override;
};

#endif
