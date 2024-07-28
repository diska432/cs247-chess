#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <memory>
#include "chess.h"
#include "render/textrender.h"
#include "inputhandler.h"

class Game {
  private:
    std::shared_ptr<Chess> chess;
    std::shared_ptr<InputHandler> input;
    std::shared_ptr<TextRender> textrender;
  public: 
    Game();
    void play();
};

#endif
