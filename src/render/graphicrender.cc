#include "graphicrender.h"
#include "window.h"
#include "../chessboard.h"
#include "../piece/piece.h"
#include "../position.h"
#include <string>
#include <unordered_set>

using namespace std;

GraphicRender::GraphicRender(shared_ptr<Chessboard> chessboard) : Render(chessboard) {};

void GraphicRender::addUpdatedPosition(std::shared_ptr<Position> p) {
  positions.push_back(p);
}

void GraphicRender::update() {
  for (auto& p : positions) {
    drawSquare(p);
  }
  positions.clear();
}

void GraphicRender::drawSquare(std::shared_ptr<Position> p) {
  int i=7-p->getX(), j=p->getY();
  shared_ptr<Piece> piece = chessboard->getSquare(*p);
  int x = 100 + 50*j, y = 50 + 50*i;
  window.fillRectangle(x-25, y-25, 50, 50, Xwindow::White);
  if (piece != nullptr) {
    window.drawString(100 + 50*j, 50 + 50*i, getChar(piece));
  } else {
    window.drawString(100 + 50*j, 50 + 50*i, (isWhite(*p) ? "_" : " "));
  }
}

void GraphicRender::render() {
  int i=0, j=0;
  for (; i<8; i++) {
    j=0;
    window.drawString(50 + 50*j, 50 + 50*i, to_string(8-i));
    for (; j<8; j++) {
      Position p{7-i, j};
      shared_ptr<Piece> piece = chessboard->getSquare(p);
      int x = 100 + 50*j, y = 50 + 50*i;
      if (piece != nullptr) {
        window.drawString(x, y, getChar(piece));
      } else {
        window.drawString(x, y, (isWhite(p) ? "_" : " "));
      }
    }
  }
  vector<string> ranks = {"a", "b", "c", "d", "e", "f", "g", "h"};
  for (int t=0; t<ranks.size(); t++) {
    window.drawString(100 + 50*t, 50 + 50*8, ranks[t]);
  }
};

string GraphicRender::getChar(const shared_ptr<Piece>& piece) const {
  char team = piece->getTeam();
  char symbol = piece->getSymbol();

  if (team == 'b') {
    switch (symbol) {
      case 'p':
        return "p";
        break;
      case 'r':
        return "r";
        break;
      case 'b':
        return "b";
        break;
      case 'n':
        return "n";
        break;
      case 'q':
        return "q";
        break;
      case 'k':
        return "k";
        break;
      case 'f':
        return "f";
        break;
      default:
        return " ";
    }
  } else if (team == 'w') {
    switch (symbol) {
      case 'p':
        return "P";
        break;
      case 'r':
        return "R";
        break;
      case 'b':
        return "B";
        break;
      case 'n':
        return "N";
        break;
      case 'q':
        return "Q";
        break;
      case 'k':
        return "K";
        break;
      case 'f':
        return "F";
        break;
      default:
        return " ";
    }
  }
}
