#include "textrender.h"
#include "../chessboard.h"
#include "../piece/piece.h"
#include "../position.h"
#include <iostream>

using namespace std;

TextRender::TextRender(Chessboard *chessboard, ostream& out) : Render(chessboard), out(out) {};

void TextRender::render() {
  for (int i=0; i<8; i++) {
    out << 8-i << " ";
    for (int j=0; j<8; j++) {
      // Position p{j, 7-i};
      Position p{7-i, j};
      // cout << "a ";
      shared_ptr<Piece> piece = chessboard->getSquare(p);
      if (piece != nullptr) {
        cout << getChar(piece) << " ";
      } else {
        cout << "  ";
      }
    }
    out << "\n";
  }
  out << "\n";

  out << "  ";
  for (char i='a'; i<='h'; i++) {
    out << i;
  }
  out << "\n";
}

char TextRender::getChar(const shared_ptr<Piece>& piece) const {
  char team = piece->getTeam();
  char symbol = piece->getSymbol();

  if (team == 'w') {
    switch (symbol) {
      case 'p':
        return 'P';
        break;
      // figure out how to display everything else
      case 'r':
        return 'R';
        break;
      default:
        return ' ';
    }
  } else if (team == 'b') {
    switch (symbol) {
      case 'p':
        return 'p';
        break;
      case 'r':
        return 'r';
        break;
      default:
        return ' ';
    }
  }
}


