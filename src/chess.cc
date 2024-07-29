#include "chess.h"
#include "position.h"
#include "move.h"
#include "render/graphicrender.h"
#include <memory>

using namespace std;

Chess::Chess() : chessboard(std::make_shared<Chessboard>()) {}

shared_ptr<Chessboard> Chess::getChessboard() const {
  return chessboard;
}

shared_ptr<GraphicRender> Chess::getGraphicRender() const {
  return graphicrender;
}

void Chess::setGraphicRender(shared_ptr<GraphicRender> gr) {
  graphicrender = gr;
}

void Chess::setInitBackdrop(bool b) { initBackdrop = b; };
bool Chess::getInitBackdrop() { return initBackdrop; };

void Chess::setInGame(bool b) { inGame = b; };
bool Chess::getInGame() { return inGame; };

void Chess::setInSetup(bool b) { inSetup = b; };
bool Chess::getInSetup() { return inSetup; };

void Chess::switchTeam() {
  if (currTeam == 'w') {
    currTeam = 'b';
  } else if (currTeam == 'b') {
    currTeam = 'w';
  }
}

void Chess::setupPlacePiece(Position p, std::shared_ptr<Piece> piece) {
  if (!inSetup) throw NotInSetupModeException();
  chessboard->placePiece(p, piece);
}

void Chess::setupRemovePiece(Position p) {
  if (!inSetup) throw NotInSetupModeException();
  chessboard->clearSquare(p);
}

void Chess::setupSetCurrTeam(char c) {
  currTeam = c;
}

void Chess::makeMove(Position from, Position to, char promotion) {
  /*
  Castle?
  En passent?
  Capture?
  Move?
  */
  chessboard->makeMove(from, to, promotion);
  graphicrender->addUpdatedPosition(make_shared<Position>(from));
  graphicrender->addUpdatedPosition(make_shared<Position>(to));
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
