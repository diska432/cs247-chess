#include "graphicrender.h"
#include "window.h"
#include "../chessboard.h"
#include "../piece/piece.h"
#include "../position.h"
#include <string>
#include <unordered_set>

using namespace std;

GraphicRender::GraphicRender(shared_ptr<Chessboard> chessboard) : Render(chessboard) {};

void GraphicRender::render() {
  int i=0, j=0;
  for (; i<8; i++) {
    j=0;
    window.drawString(50 + 50*j, 50 + 50*i, to_string(8-i));
    for (; j<8; j++) {
      Position p{7-i, j};
      shared_ptr<Piece> piece = chessboard->getSquare(p);
      if (piece != nullptr) {
        window.drawString(100 + 50*j, 50 + 50*i, getChar(piece));
      } else {
        window.drawString(100 + 50*j, 50 + 50*i, (isWhite(p) ? "_" : " "));
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
      default:
        return " ";
    }
  }
}
