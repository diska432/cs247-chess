#ifndef PRINCESS_H
#define PRINCESS_H
#include "piece.h"

class Princess : public Piece {
  public:
    Princess(char team);
    std::vector<Position>getAllMoves(std::shared_ptr<Chessboard>, Position) override;
};

#endif
