#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../position.h"

class Player {
  protected:
    bool isHuman; // boolean representing if player is human or computer
    char color; // color is either "W" or "B", representing which 
    // vector<Piece> captured;
    int score; // how many points the player scored
  public:
    virtual ~Player(); // virtual destructor to make it an abstract class
    virtual std::pair<Position, Position> getMove() = 0; // virtual getMove
    bool isHuman(); // getter for if they're human
    char getColor(); // getter for they're color
};

#endif
