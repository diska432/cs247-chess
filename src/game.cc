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
    if(chess->getChessboard()->isCheckmate('w') ) {
      scores[1]++;
      cout << "Checkmate! Black wins!" << endl;
      res = 0;
    } else if(chess->getChessboard()->isCheckmate('b')){
      scores[0]++;
      cout << "Checkmate! White wins!" << endl;
      res = 0;
    }
    if (res == 0) {
      // game is over, so break out and print scores
      cout << "Final Score: " << endl;
      cout << "White: " << scores[0] << endl;
      cout << "Black: " << scores[1] << endl;
      break;
    }

    // if (chess->getInSetup() || chess->getInGame()) {
    textrender->render();
    if (!chess->getInitBackdrop()) {
      graphicrender->render();
      chess->setInitBackdrop(true);
    } else {
      graphicrender->update();
    }
    // }
  }
  /*

  do {
    int res = input->handleInput();


    // if (res == 0) {
    //   // game is over, so break out and print scores
    //   break;
    // }

    // if (chess->getInSetup() || chess->getInGame()) {
    if (chess->getInGame() || chess->getInSetup()) {
      textrender->render();
      if (!chess->getInitBackdrop()) {
        graphicrender->render();
        chess->setInitBackdrop(true);
      } else {
        graphicrender->update();
      }
    }

    // }
  }
  while (chess->getInGame() || chess->getInSetup());
  */
}
