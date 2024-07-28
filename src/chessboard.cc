#include "chessboard.h"
#include "piece/piece.h"
#include "piece/pawn.h"
#include "piece/rook.h"

#include <memory>

using namespace std;

Chessboard::Chessboard() : board(8, vector<shared_ptr<Piece>>(8, nullptr)) {
  for (int i=0; i<width; i++) {
    board[1][i] = make_shared<Pawn>('w'); 
    board[6][i] = make_shared<Pawn>('b'); 
  }
  board[0][0] = make_shared<Rook>('w');
};

void Chessboard::placePiece(int x, int y, shared_ptr<Piece> piece) {
  board[x][y] = piece;
}

bool Chessboard::positionInRange(Position p) const {
  return (
    p.getX() >= 0 && p.getX() < width &&
    p.getY() >= 0 && p.getY() < width 
  );
}

shared_ptr<Piece> Chessboard::getSquare(Position p) const {
  if (!positionInRange(p)) {
    // throw some error
    cout << "Yo not in range ( we will be throwing an error here eventually )\n";
  }
  return board[p.getX()][p.getY()];
}

