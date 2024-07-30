#include "textrender.h"
#include "../chessboard.h"
#include "../piece/piece.h"
#include "../position.h"
#include <iostream>

using namespace std;

TextRender::TextRender(shared_ptr<Chessboard> chessboard, ostream& out) : Render(chessboard), out(out) {};

void TextRender::render() {
  for (int i=0; i<8; i++) {
    out << 8-i << " ";
    for (int j=0; j<8; j++) {
      Position p{7-i, j};
      shared_ptr<Piece> piece = chessboard->getSquare(p);
      if (piece != nullptr) {
        cout << getChar(piece) << " ";
      } else {
        cout << (isWhite(p) ? "_" : " ") << " ";
      }
    }
    out << "\n";
  }
  out << "\n";
  out << "  ";
  for (char i='a'; i<='h'; i++) {
    out << i << " ";
  }
  out << "\n";
  out << (chessboard->isInCheck('w') || chessboard->isInCheck('b') ? "Check!" : " ") << "\n";
  out << "\n";
}

string TextRender::getChar(const shared_ptr<Piece>& piece) const {
  char team = piece->getTeam();
  char symbol = piece->getSymbol();

  if (team == 'w') {
    switch (symbol) {
      case 'p':
        return "♙";
        break;
      case 'r':
        return "♖";
        break;
      case 'b':
        return "♗";
        break;
      case 'n':
        return "♘";
        break;
      case 'q':
        return "♕";
        break;
      case 'k':
        return "♔";
        break;
      case 'f':
        return "F";
        break;
      default:
        return " ";
    }
  } else if (team == 'b') {
    switch (symbol) {
      case 'p':
        return "♟";
        break;
      case 'r':
        return "♜";
        break;
      case 'b':
        return "♝";
        break;
      case 'n':
        return "♞";
        break;
      case 'q':
        return "♛";
        break;
      case 'k':
        return "♚";
        break;
      case 'f':
        return "f";
        break;
      default:
        return " ";
    }
  }
}


