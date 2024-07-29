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
    int width = 8;
    Position potentialEnPassant;
  public:
    Chessboard();
    void clearBoard();
    void placePiece(Position p, std::shared_ptr<Piece>);
    std::shared_ptr<Piece> getSquare(Position&) const;
    void clearSquare(Position);
    std::vector<std::shared_ptr<Position>> makeMove(Position, Position, char);
    int getWidth() const;
    bool validNumberOfKings() const;
    bool validPawnPlacement() const;
    bool positionInRange(Position&) const;
    bool isValidMove(Position s, Position e) const;

    std::vector<std::shared_ptr<Position>> getPiecePositions(char);
    char opponentTeam(char);
    bool isSquareUnderAttack(Position, char);

    bool isInCheck(char team);
    bool isCheckmate(char team);

    Position getKingPosition(char team);

    Position getPotentialEnPassant() const;
    bool isStalemate(char team);

};

#endif
