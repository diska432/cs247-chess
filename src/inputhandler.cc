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
#include "player/player.h"
#include "player/human/human.h"
#include "player/computer/level1.h"
#include <memory>

using namespace std;

/*
TODO: add helper message and aid ui for CLI
*/

shared_ptr<Computer> InputHandler::createLevel(int level) {
  switch (level) {
    case 1:
      return make_shared<Level1>(game->getChessboard());
    default:
      return make_shared<Level1>();
  }
}

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
      if (!game->getChessboard()->validNumberOfKings()) {
        cout << "Invalid game configuration: each player must have 1 king\n";
        continue;
      } else if (!game->getChessboard()->validPawnPlacement()) {
        cout << "Invalid game configuration: pawn must not be on the back ranks\n";
        continue;
      }
      game->setInSetup(false);
      cout << "You have successfully exited setup mode\n";
      break;
    } else {
      cout << "Invalid input in setup mode\n";
      continue;
    }
  }
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
    pair<Position, Position> move = game->players[game->currTeam]->getMove();


    // string f, t;
    // cin >> f >> t;
    char promotion = '_';
    if (cin.peek() != '\n') {
      cin >> promotion;
    }
    try {
      game->makeMove(move.first, move.second, promotion);
      game->switchTeam();

      if (!game->players[game->currTeam]->isHumanPlayer()) {
        pair<Position, Position> move = game->players[game->currTeam]->getMove();
        game->makeMove(move.first, move.second, promotion);
        game->switchTeam();
      }
    } catch (exception& e) {
      cout << "Invalid move. Try again.\n";
    }


    // cout << "someone moving type shi\n";
    // game->getChessboard()->makeMove();
  } 
  else if (op1 == "game") {
    if (game->getInGame()) {
      cout << "You are already in a game. Please finish the current game before starting a new one.\n";
    }

    string p1, p2;
    cin >> p1 >> p2;

    string p1s = p1.substr(0, p1.size() - 1);
    string p2s = p2.substr(0, p2.size() - 1);

    int p1Int = p1.back() - '0' - 1;
    int p2Int = p2.back() - '0' - 1;

    game->setInGame(true);
    if (p1 == "human" && p2 == "human") {
      game->players.emplace('w', make_shared<Human>());
      game->players.emplace('b', make_shared<Human>());
    } else if (p1 == "human" && p2s == "computer") {
      game->players.emplace('w', make_shared<Human>());
      game->players.emplace('b', createLevel(p2Int));

    } else if (p1s == "computer" && p2 == "human") {
      game->players.emplace('w', createLevel(p1Int));
      game->players.emplace('b', make_shared<Human>());

    } else if (p1s == "computer" && p2s == "computer") {
      game->players.emplace('w', createLevel(p1Int));
      game->players.emplace('b', createLevel(p2Int));
    } else {
      cout << "Invalid game type. Try again.\n";
      game->setInGame(false);
    }
  } 
  else {
    if (cin.eof()) {
      return 0;
    }
    cout << "Invalid command: " << op1 << "\n";
  }
  return 1;
}
