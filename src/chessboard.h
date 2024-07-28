#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
#include <memory>
#include <vector>
#include "piece/piece.h"
#include "position.h"

class Piece;

class Chessboard {
  private:
    std::vector<std::vector<std::shared_ptr<Piece>>> board;
    bool positionInRange(Position p) const;
    int width = 8;
  public:
    Chessboard();
    void placePiece(int x, int y, std::shared_ptr<Piece> piece);
    std::shared_ptr<Piece> getSquare(Position p) const;
};

#endif
