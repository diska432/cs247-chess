#ifndef TEXTRENDER_H
#define TEXTRENDER_H
#include <iostream>
#include <memory>
#include "render.h"
#include "../chessboard.h"
#include "../piece/piece.h"

class TextRender : Render {
  private:
    std::ostream &out;
  public:
    TextRender(Chessboard* board, std::ostream& out);
    void render() override;
    char getChar(const std::shared_ptr<Piece>& piece) const;
};

#endif
