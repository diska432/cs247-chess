#include "game.h"
#include "chess.h"
#include <memory>

using namespace std;

// Game::Game() : chess(), input(make_shared<Chess>(chess)), textrender(chess.getChessboard(), cout) {};
Game::Game() : chess(make_shared<Chess>()), textrender(make_shared<TextRender>(chess->getChessboard(), cout)), graphicrender(make_shared<GraphicRender>(chess->getChessboard())) {
  input = make_shared<InputHandler>(chess, textrender, graphicrender);
  chess->setGraphicRender(graphicrender);
};

void Game::play() {

  for(;;) {
    int res = input->handleInput();
    if (res == 0) {
      chess->getFinalScores();
      break;
    }

    if (chess->getInSetup() || chess->getInGame()) { 
      textrender->render();
      if (!chess->getInitBackdrop()) {
        graphicrender->render();
        chess->setInitBackdrop(true);
      } else {
        graphicrender->update();
      }
    }

  }
}
