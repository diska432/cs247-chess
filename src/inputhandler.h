#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <iostream>
#include "chess.h"
#include "render/textrender.h"
#include "player/computer/computer.h"
#include "render/graphicrender.h";
#include <memory>

class InputHandler {
  private:
    std::shared_ptr<Chess> game;
    std::shared_ptr<TextRender> textrender;
    std::shared_ptr<GraphicRender> graphicrender;
    bool inSetup = false;
    void enterSetup();
  public: 
    InputHandler(std::shared_ptr<Chess> game, std::shared_ptr<TextRender> textrender, std::shared_ptr<GraphicRender> graphicrender);
    int handleInput();
};

#endif
