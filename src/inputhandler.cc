#include "inputhandler.h"
#include "exception.h"
#include "piece/piece.h"
#include "piece/pawn.h"
#include "piece/rook.h"
#include "piece/knight.h"
#include "piece/bishop.h"
#include "piece/queen.h"
#include "piece/king.h"
#include "chess.h"
#include "render/textrender.h"
#include <memory>

using namespace std;

/*
TODO: add helper message and aid ui for CLI
*/

InputHandler::InputHandler(shared_ptr<Chess> game, std::shared_ptr<TextRender> textrender) : game(game), textrender(textrender) {};

void InputHandler::enterSetup() {
  game->setInSetup(true);
  game->getChessboard()->clearBoard();

  string op1;
  
  while (cin >> op1) {
    if (op1 == "+") {
      char p; string coord;
      cin >> p >> coord;
      char team = (p >= 'a') ? 'b' : 'w';
      Position pos = Position{coord};
      shared_ptr<Piece> piece;

      switch (p) {
        case 'p': // prbnqk
        case 'P':
          piece = make_shared<Pawn>(team);
          break;
        case 'r': 
        case 'R':
          piece = make_shared<Rook>(team);
          break;
        case 'b': 
        case 'B':
          piece = make_shared<Bishop>(team);
          break;
        case 'n': 
        case 'N':
          piece = make_shared<Knight>(team);
          break;
        case 'q': 
        case 'Q':
          piece = make_shared<Queen>(team);
          break;
        case 'k': 
        case 'K':
          piece = make_shared<King>(team);
          break;
        default:
          cout << "Invalid piece type\n";
          continue;
      }

      try {
        game->setupPlacePiece(pos, piece);
      } catch (...) {
        cout << "Unable to add piece due to coordinates out of range\n";
        continue;
      }

      string breaker(2*(game->getChessboard()->getWidth() + 1), '-');
      cout << breaker << "\n";
      textrender->render();
    } else if (op1 == "-") {
      string coord;
      cin >> coord;
      Position pos = Position{coord};
      try {
        game->setupRemovePiece(pos);
      } catch (...) {
        cout << "Unable to remove piece due to coordinates out of range\n";
        continue;
      }

      string breaker(2*(game->getChessboard()->getWidth() + 1), '-');
      cout << breaker << "\n";
      textrender->render();
    } else if (op1 == "=") {
      string color;
      cin >> color;
      if (color == "white") {
        game->setupSetCurrTeam('w');
      } else if (color == "black") {
        game->setupSetCurrTeam('b');
      } else {
        cout << "Invalid team colour\n";
        continue;
      }
    } else if (op1 == "done") {
      cout << "You have successfully exited setup mode\n";
      break;
    } else {
      cout << "Invalid input in setup mode\n";
      continue;
    }
  }

  game->setInSetup(false);
}

int InputHandler::handleInput() {
  string op1;
  cin >> op1;

  if (op1 == "setup") {
    if (!game->getInGame()) {
      // enter setup mode
      enterSetup();
    } else {
      cout << "You can't enter 'setup' mode while you are playing the game.\n";
    }
    enterSetup();
  } else if (op1 == "resign") {
    cout << "someonen resigning type sh\n";
  } else if (op1 == "move") {
    string f, t;
    cin >> f >> t;
    char promotion;
    if (cin.peek() != '\n') {
      cin >> promotion;
    }
    try {
      Position from{f};
      Position to{t};
      game->makeMove(from, to, promotion);
    } catch (exception& e) {
      cout << "Invalid move. Try again.\n";
    }
    // cout << "someone moving type shi\n";
    // game->getChessboard()->makeMove();
  } else {
    if (cin.eof()) {
      return 0;
    }
    cout << "Invalid command: " << op1 << "\n";
  }
  return 1;
}
