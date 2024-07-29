#ifndef GRAPHICRENDER_H
#define GRAPHICRENDER_H
#include <iostream>
#include <memory>
#include <unordered_set>
#include "render.h"
#include "window.h"
#include "../chessboard.h"
#include "../chess.h"
#include "../piece/piece.h"

class GraphicRender : public Render {
  private:
    Xwindow window;
    std::vector<std::shared_ptr<Position>> positions;
  public:
    GraphicRender(std::shared_ptr<Chessboard> chessboard);
    void render() override;
    std::string getChar(const std::shared_ptr<Piece>& piece) const;

    void addUpdatedPosition(std::shared_ptr<Position> p);
    void drawSquare(std::shared_ptr<Position> p);
    void update();
};

#endif
