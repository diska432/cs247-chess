#ifndef GRAPHICRENDER_H
#define GRAPHICRENDER_H
#include <iostream>
#include <memory>
#include "render.h"
#include "window.h"
#include "../chessboard.h"
#include "../piece/piece.h"

class GraphicRender : Render {
  private:
    Xwindow window;
  public:
    GraphicRender(Chessboard* chessboard);
    void render() override;
    std::string getChar(const std::shared_ptr<Piece>& piece) const;
};

#endif
