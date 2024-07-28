#include "game.h"
#include "chess.h"
#include <memory>

using namespace std;

Game::Game() : chess(), input(make_shared<Chess>(chess)), textrender(chess.getChessboard(), cout) {};

void Game::play() {
  for(;;) {
    int res = input.handleInput();

    if (res == 0) {
      // game is over, so break out and print scores
      break;
    }
    textrender.render();
    cout << "We would render board rn\n";
  }
}
