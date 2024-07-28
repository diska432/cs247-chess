#include "chessboard.h"
#include "piece/piece.h"
#include "piece/pawn.h"
#include "piece/rook.h"
#include "piece/knight.h"
#include "piece/bishop.h"
#include "piece/queen.h"
#include "piece/king.h"
#include <memory>

using namespace std;

Chessboard::Chessboard() : board(8, vector<shared_ptr<Piece>>(8, nullptr)) {
  for (int i=0; i<width; i++) {
    board[1][i] = make_shared<Pawn>('w'); 
    board[6][i] = make_shared<Pawn>('b'); 
  }
  // White back-rank pieces
  board[0][0] = make_shared<Rook>('w');
  board[0][1] = make_shared<Knight>('w');
  board[0][2] = make_shared<Bishop>('w');
  board[0][3] = make_shared<Queen>('w');
  board[0][4] = make_shared<King>('w');
  board[0][5] = make_shared<Bishop>('w');
  board[0][6] = make_shared<Knight>('w');
  board[0][7] = make_shared<Rook>('w');
  
  // Black back-rank pieces
  board[7][0] = make_shared<Rook>('b');
  board[7][1] = make_shared<Knight>('b');
  board[7][2] = make_shared<Bishop>('b');
  board[7][3] = make_shared<Queen>('b');
  board[7][4] = make_shared<King>('b');
  board[7][5] = make_shared<Bishop>('b');
  board[7][6] = make_shared<Knight>('b');
  board[7][7] = make_shared<Rook>('b');
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

