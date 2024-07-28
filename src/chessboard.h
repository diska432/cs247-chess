#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
#include <memory>
#include <vector>
#include "piece/piece.h"
#include "position.h"
#include "exception.h"

class Piece;

class Chessboard {
  private:
    std::vector<std::vector<std::shared_ptr<Piece>>> board;
    bool positionInRange(Position p) const;
    int width = 8;
  public:
    Chessboard();
    void clearBoard();
    void placePiece(Position p, std::shared_ptr<Piece> piece);
    std::shared_ptr<Piece> getSquare(Position p) const;
    void clearSquare(Position p);
    void makeMove(Position from, Position to, char promotion);
    int getWidth() const;
};

#endif
