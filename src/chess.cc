#include "chess.h"

Chessboard* Chess::getChessboard() {
  return &chessboard;
}

void Chess::switchTeam() {
  if (currTeam == 'w') {
    currTeam = 'b';
  } else if (currTeam == 'b') {
    currTeam = 'w';
  }
}
