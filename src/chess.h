#ifndef CHESS_H
#define CHESS_H
#include <iostream>
#include <memory>
#include <stack>
#include "chessboard.h"
#include "position.h"
#include "move.h"
#include "player/player.h"
#include "render/graphicrender.h"
#include <map>

class GraphicRender;

class Chess {
  private:
    std::shared_ptr<Chessboard> chessboard;
    std::shared_ptr<std::stack<AtomicMove>> moves;
    std::shared_ptr<GraphicRender> graphicrender;
    std::vector<double>scores{0, 0};

    bool inSetup = false;
    bool inGame = false;
    bool initBackdrop = false;
  public:
    Chess();

    std::shared_ptr<Chessboard> getChessboard() const;
    std::shared_ptr<GraphicRender> getGraphicRender() const;
    void setGraphicRender(std::shared_ptr<GraphicRender> gr);

    void resetBoard();

    char currTeam = 'w';
    std::map<char, std::shared_ptr<Player>> players; 

    void switchTeam();

    void makeMove(Position from, Position to, char promotion);
    void makeUndo();

    // Getter/setter for inSetup flag
    void setInSetup(bool b);
    bool getInSetup();

    void setInitBackdrop(bool b);
    bool getInitBackdrop();

    // Getter/setter for inGame flag
    void setInGame(bool b);
    bool getInGame();

    // Setup commands
    void setupPlacePiece(Position p, std::shared_ptr<Piece> piece);
    void setupRemovePiece(Position p);
    void setupSetCurrTeam(char c);
    void resign();
    void getFinalScores();
    std::string getWinner();


};

#endif
