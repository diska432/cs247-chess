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

    bool inSetup = false;
    bool inGame = false;
  public:
    Chess();
    std::shared_ptr<Chessboard> getChessboard();
    void switchTeam();
    void makeMove(Position from, Position to, char promotion);

    // Getter/setter for inSetup flag
    void setInSetup(bool inSetup);
    bool getInSetup();

    // Getter/setter for inGame flag
    void setInGame(bool inGame);
    bool getInGame();
};

#endif
