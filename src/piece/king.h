#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece {
  public:
    King(char team);
    std::vector<Position>getAllMoves(std::shared_ptr<Chessboard>, Position) override;
};

#endif
