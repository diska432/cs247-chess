#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight : public Piece {
  public:
    Knight(char symbol, char color);
    std::vector<Position>getAllMoves(Chessboard &cb) override;
};

#endif