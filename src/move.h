#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <stack>
#include "position.h"
#include "piece/piece.h"

class AtomicMove {
  private:
    class Move {
      private:
        char type;
        char team;
        std::shared_ptr<Piece> piece;
        Position p1;
        Position p2;
      public:
        Move(char type, char team, std::shared_ptr<Piece> piece, Position p1, Position p2);
    };
    std::stack<Move> moveStack;
  public:
    AtomicMove();
    void addMove(char type, char team, std::shared_ptr<Piece> piece, Position p1, Position p2);
};

#endif
