#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../position.h"

class Player {
  protected:
    bool isHuman; // boolean representing if player is human or computer
    char color; // color is either "W" or "B", representing which 
    // vector<Piece> captured;
    int score;
  public:
    virtual ~Player();
    virtual std::pair<Position, Position> getMove() = 0;
    bool isHuman();
    char getColor();
};

#endif
