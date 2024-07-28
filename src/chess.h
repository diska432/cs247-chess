#ifndef CHESS_H
#define CHESS_H
#include <iostream>
#include "chessboard.h"

class Chess {
  private:
    Chessboard chessboard;
    char currTeam = 'w';
  public:
    Chessboard* getChessboard();
    void switchTeam();
};

#endif
