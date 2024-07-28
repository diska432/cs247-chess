#ifndef PIECE_H
#define PIECE_H
#include "../position.h"
#include "../chessboard.h"

class Chessboard;

class Piece {
  char symbol;
  char team;

  public:
    Piece(char symbol, char team);
    virtual std::vector<Position>getAllMoves(Chessboard &cb, Position p) = 0;
    char getTeam() const;
    char getSymbol() const;
};

#endif
