#ifndef CHESS_H
#define CHESS_H
#include <iostream>
#include <memory>
#include <stack>
#include "chessboard.h"
#include "position.h"
#include "move.h"
#include "player/player.h"
#include <map>

class Chess {
  private:
    std::shared_ptr<Chessboard> chessboard;
    std::shared_ptr<std::stack<AtomicMove>> moves;
    char currTeam = 'w';

    bool inSetup = false;
    bool inGame = false;
  public:
    Chess();
    std::shared_ptr<Chessboard> getChessboard();
    std::map<char, std::shared_ptr<Player>> players; // Modified line

    void switchTeam();

    void makeMove(Position from, Position to, char promotion);
    void makeUndo();

    // Getter/setter for inSetup flag
    void setInSetup(bool b);
    bool getInSetup();

    // Getter/setter for inGame flag
    void setInGame(bool b);
    bool getInGame();

    // Setup commands
    void setupPlacePiece(Position p, std::shared_ptr<Piece> piece);
    void setupRemovePiece(Position p);
    void setupSetCurrTeam(char c);
};

#endif
