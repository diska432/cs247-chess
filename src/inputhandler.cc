#include "inputhandler.h"
#include "chess.h"

#include "player/player.h"
#include "player/human/human.h"
#include "player/computer/level1.h"
#include <memory>

using namespace std;

/*
TODO: add helper message and aid ui for CLI
*/

InputHandler::InputHandler(shared_ptr<Chess> game) : game(game) {};

void InputHandler::enterSetup() {
  game->setInSetup(true);

  string op1;
  
  while (cin >> op1) {
    if (op1 == "+") {
      break;
    } else if (op1 == "-") {
      break;
    } else if (op1 == "=") {
      break;
    } else if (op1 == "done") {
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
  } 
  else if (op1 == "game") {
    string p1, p2;
    cin >> p1 >> p2;

    int p2Int = p2.back() - '0' - 1;
    p2.pop_back();

    game->setInGame(true);

    if (p1 == "human" && p2 == "human") {
      game->players.emplace('w', std::make_shared<Human>());
      game->players.emplace('b', std::make_shared<Human>());
    } else if (p1 == "human" && p2 == "computer") {
      game->players.emplace('w', std::make_shared<Human>());
      game->players.emplace('b', std::make_shared<Level1>());

    } else if (p1 == "computer" && p2 == "human") {
      game->players.emplace('w', std::make_shared<Level1>());
      game->players.emplace('b', std::make_shared<Human>());

    } else if (p1 == "computer" && p2 == "computer") {
      game->players.emplace('w', std::make_shared<Level1>());
      game->players.emplace('b', std::make_shared<Level1>());
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
