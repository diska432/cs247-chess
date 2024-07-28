#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook : public Piece {
  public:
    Rook(char team);
    std::vector<Position>getAllMoves(std::shared_ptr<Chessboard>, Position) override;
};

#endif
