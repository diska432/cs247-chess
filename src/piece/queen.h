#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece {
  public:
    Queen(char team);
    std::vector<Position>getAllMoves(Chessboard &cb, Position p) override;
};

#endif
