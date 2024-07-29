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
    bool positionInRange(Position&) const;
    int width = 8;
  public:
    Chessboard();
    void clearBoard();
    void placePiece(Position p, std::shared_ptr<Piece>);
    std::shared_ptr<Piece> getSquare(Position&) const;
    void clearSquare(Position);
    void makeMove(Position, Position, char);
    int getWidth() const;
    bool validNumberOfKings() const;
    bool validPawnPlacement() const;
    bool isValidMove(Position s, Position e) const;
};

#endif
