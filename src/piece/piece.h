#ifndef PIECE_H
#define PIECE_H
#include "../position.h"
#include "../chessboard.h"

class Chessboard;

class Piece {
  char symbol;
  bool moved = false;

  protected:
    char team;

  public:
    Piece(char symbol, char team);
    virtual std::vector<Position>getAllMoves(std::shared_ptr<Chessboard>, Position p) = 0;
    char getTeam() const;
    char getSymbol() const;

    void setMoved(bool b);
    bool getMoved() const;
};

#endif
