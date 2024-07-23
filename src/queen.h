#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece {
  public:
    Queen(char symbol, char color, Position pos);
    vector<Position>getAllMoves(Chessboard &cb) override;
};

#endif
