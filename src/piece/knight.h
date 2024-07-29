#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight : public Piece {
  public:
    Knight(char team);
    std::vector<Position>getAllMoves(std::shared_ptr<Chessboard>, Position) override;
};

#endif
