#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "chess.h"
#include "render/textrender.h"
#include "inputhandler.h"

class Game {
  private:
    Chess chess;
    InputHandler input;
    TextRender textrender;
    // Render render;
    
  public: 
    Game();
    void play();
};

#endif
