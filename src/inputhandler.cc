#include "inputhandler.h"
#include "chess.h"
#include <memory>

using namespace std;

InputHandler::InputHandler(shared_ptr<Chess> game) : game(game) {};

void InputHandler::enterSetup() {
  cout << "Handling setup\n";
}

int InputHandler::handleInput() {

  string op1;
  cin >> op1;

  if (op1 == "setup") {
    enterSetup();
  } else if (op1 == "resign") {
    cout << "someonen resigning type sh\n";
  } else if (op1 == "move") {
    // cout << "someone moving type shi\n";
    game->getChessboard()->makeMove();
  } else {
    if (cin.eof()) {
      return 0;
    }
    cout << "Invalid command: " << op1 << "\n";
  }
  return 1;
}
