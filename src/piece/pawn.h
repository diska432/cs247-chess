#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn : public Piece {
  public:
    Pawn(char team);
    std::vector<Position> getAllMoves(std::shared_ptr<Chessboard>, Position) override;
    void promote();
};

#endif
