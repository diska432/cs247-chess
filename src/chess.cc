#include "chess.h"
#include "position.h"
#include "move.h"
#include <memory>

using namespace std;

Chess::Chess() : chessboard(std::make_shared<Chessboard>()) {}

shared_ptr<Chessboard> Chess::getChessboard() {
  return chessboard;
}

void Chess::setInGame(bool inGame) { inGame = inGame; };
bool Chess::getInGame() { return inGame; };

void Chess::setInSetup(bool inSetup) { inSetup = inSetup; };
bool Chess::getInSetup() { return inSetup; };

void Chess::switchTeam() {
  if (currTeam == 'w') {
    currTeam = 'b';
  } else if (currTeam == 'b') {
    currTeam = 'w';
  }
}

void Chess::makeMove(Position from, Position to, char promotion) {
  /*
  Castle?
  En passent?
  Capture?
  Move?
  */
  chessboard->makeMove(from, to, promotion);

}

void Chess::makeUndo() {
  if (moves->size() == 0) {
    // No moves made, so we cannot undo anymore
    throw InvalidMoveException();
  } else {
    // we should be able to do an undo
    cout << "we still have to implement this\n";
    // AtomicMove lastMove = moves->top();
    // moves->pop();
    // stack<Move> sequence = lastMove.moveStack;
  }
}
