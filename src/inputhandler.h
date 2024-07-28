#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <iostream>
#include "chess.h"
#include <memory>

class InputHandler {
  private:
    std::shared_ptr<Chess> game;
    bool inSetup = false;
    void enterSetup();
  public: 
    InputHandler(std::shared_ptr<Chess> game);
    int handleInput();
};

#endif
