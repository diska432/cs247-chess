#ifndef CHESS_H
#define CHESS_H
#include <iostream>
#include <memory>
#include "chessboard.h"
#include "position.h"

class Chess {
  private:
    std::shared_ptr<Chessboard> chessboard;
    char currTeam = 'w';
  public:
    Chess();
    std::shared_ptr<Chessboard> getChessboard();
    void switchTeam();
    void makeMove(Position from, Position to, char promotion);
};

#endif
