#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn : public Piece {
  public:
    Pawn(char team);
    std::vector<Position> getAllMoves(Chessboard &cb) override;
    void promote();
};

#endif
