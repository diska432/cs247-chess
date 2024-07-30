#ifndef TEXTRENDER_H
#define TEXTRENDER_H
#include <iostream>
#include <memory>
#include "render.h"
#include "../chessboard.h"
#include "../chess.h"
#include "../piece/piece.h"

class TextRender : public Render {
  private:
    std::ostream &out;
  public:
    TextRender(std::shared_ptr<Chessboard> chessboard, std::ostream& out);
    void render() override;
    std::string getChar(const std::shared_ptr<Piece>& piece) const;
};

#endif
