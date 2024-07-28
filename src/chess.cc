#include "chess.h"
#include "position.h"
#include <memory>

using namespace std;

Chess::Chess() : chessboard(std::make_shared<Chessboard>()) {}

shared_ptr<Chessboard> Chess::getChessboard() {
  return chessboard;
}

void Chess::switchTeam() {
  if (currTeam == 'w') {
    currTeam = 'b';
  } else if (currTeam == 'b') {
    currTeam = 'w';
  }
}

void Chess::makeMove(Position from, Position to, char promotion) {
  chessboard->makeMove(from, to, promotion);
}
