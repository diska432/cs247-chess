#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../position.h"

class Player {
  protected:
    bool isHuman = false; // boolean representing if player is human or computer
  public:
    virtual ~Player(); // virtual destructor to make it an abstract class
    virtual std::pair<Position, Position> getMove() = 0; // virtual getMove
    bool isHumanPlayer() const; // getter for if they're human
};

#endif
