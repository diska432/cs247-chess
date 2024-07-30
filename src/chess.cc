#include "chess.h"
#include "position.h"
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

void Chess::resetBoard() {
  chessboard = make_shared<Chessboard>(Chessboard()); // Chessboard();
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
  if (!getInGame()) {
    throw GameNotStartedException();
  }
  if (!chessboard->isValidMove(from, to)) {
    throw InvalidMoveException();
  }

  shared_ptr<Piece> piece = chessboard->getSquare(from);
  if (piece && (piece->getTeam() != currTeam)) {
    throw InvalidMoveException();
  }

  vector<shared_ptr<Position>> posToUpdate = chessboard->makeMove(from, to, promotion);
  for (auto &p : posToUpdate) {
    graphicrender->addUpdatedPosition(p);
  }
  switchTeam();
}

void Chess::resign() {
  scores[currTeam == 'w' ? 1 : 0]++;
  if(currTeam == 'w') {
    cout << "Black wins!\n";
  } else {
    cout << "White wins!\n";
  }
}

void Chess::getFinalScores() {
  cout << "Final Score:\n";
  cout << "White: " << scores[0] << endl;
  cout << "Black: " << scores[1] << endl;
}

string Chess::getWinner() {
  if(chessboard->isStalemate(currTeam)){
    scores[0] += 0.5;
    scores[1] += 0.5;
    return "Stalemate";
  }
  if(chessboard->isCheckmate(currTeam)) {
    scores[currTeam == 'w' ? 1 : 0]++;
    return currTeam == 'w' ? "Black" : "White";
  }
  return "";
}
