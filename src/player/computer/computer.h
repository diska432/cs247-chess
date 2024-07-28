#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include "../player.h"
#include "../../chessboard.h"

class Computer : public Player {
  protected:
    Chessboard* chessboard;
  public:
    Computer();
};

#endif
