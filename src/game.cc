#include "game.h"
#include "chess.h"
#include <memory>

using namespace std;

// Game::Game() : chess(), input(make_shared<Chess>(chess)), textrender(chess.getChessboard(), cout) {};
Game::Game() : chess(make_shared<Chess>()), textrender(make_shared<TextRender>(chess->getChessboard().get(), cout)) {
  input = make_shared<InputHandler>(chess, textrender);
};

void Game::play() {
  for(;;) {
    int res = input->handleInput();

    if (res == 0) {
      // game is over, so break out and print scores
      break;
    }

    // if (chess->getInSetup() || chess->getInGame()) {
    textrender->render();
    // }
  }
}
