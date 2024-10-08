#include "game.h"
#include "chess.h"
#include <memory>

using namespace std;

Game::Game() : chess(make_shared<Chess>()), textrender(make_shared<TextRender>(chess->getChessboard(), cout)), graphicrender(make_shared<GraphicRender>(chess->getChessboard())) {
  input = make_shared<InputHandler>(chess, textrender, graphicrender);
  chess->setGraphicRender(graphicrender);
};

void Game::resetGame() {
  chess->resetBoard();
  graphicrender->updateChessboard(chess->getChessboard());
  textrender->updateChessboard(chess->getChessboard());
}

void Game::play() {
  for(;;) {
    int res = input->handleInput();
    if (res == 0) {
      chess->getFinalScores();
      break;
    } else if (res == 2) {
      resetGame();
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
