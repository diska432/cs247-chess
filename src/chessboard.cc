#include "chessboard.h"
#include "exception.h"
#include "piece/piece.h"
#include "piece/pawn.h"
#include "piece/rook.h"
#include "piece/knight.h"
#include "piece/bishop.h"
#include "piece/queen.h"
#include "piece/king.h"
#include <memory>

using namespace std;

/*
TODO: properly handle exceptions and invalid inputs
*/

Chessboard::Chessboard() : board(8, vector<shared_ptr<Piece>>(8, nullptr)) {
  for (int i=0; i<width; i++) {
    board[1][i] = make_shared<Pawn>('b'); 
    board[6][i] = make_shared<Pawn>('w'); 
  }
  // Black back-rank pieces
  board[0][0] = make_shared<Rook>('b');
  board[0][1] = make_shared<Knight>('b');
  board[0][2] = make_shared<Bishop>('b');
  board[0][3] = make_shared<Queen>('b');
  board[0][4] = make_shared<King>('b');
  board[0][5] = make_shared<Bishop>('b');
  board[0][6] = make_shared<Knight>('b');
  board[0][7] = make_shared<Rook>('b');
  
  // White back-rank pieces
  board[7][0] = make_shared<Rook>('w');
  board[7][1] = make_shared<Knight>('w');
  board[7][2] = make_shared<Bishop>('w');
  board[7][3] = make_shared<Queen>('w');
  board[7][4] = make_shared<King>('w');
  board[7][5] = make_shared<Bishop>('w');
  board[7][6] = make_shared<Knight>('w');
  board[7][7] = make_shared<Rook>('w');
};

void Chessboard::clearBoard() {
  for (int i=0; i<width; i++) {
    for (int j=0; j<width; j++) {
      board[i][j] = nullptr;
    }
  }
}

int Chessboard::getWidth() const { return width; };

void Chessboard::placePiece(Position p, shared_ptr<Piece> piece) {
  if (!positionInRange(p)) {
    // throw some error
    throw InvalidMoveException();
  } else {
    board[p.getX()][p.getY()] = piece;
  }
}

void Chessboard::clearSquare(Position p) {
  if (!positionInRange(p)) {
    // throw some error
    throw InvalidMoveException();
  } else {
    board[p.getX()][p.getY()] = nullptr;
  }
}

bool Chessboard::positionInRange(Position& p) const {
  // return true;
  return (
    p.getX() >= 0 && p.getX() < width &&
    p.getY() >= 0 && p.getY() < width 
  );
}

shared_ptr<Piece> Chessboard::getSquare(Position& p) const {
  if (!positionInRange(p)) {
    // throw some error
    throw InvalidMoveException();
  } else {
    return board[p.getX()][p.getY()];
  }
}

void Chessboard::makeMove(Position from, Position to, char promotion) {
  // std::cout << "Making move from " << from.getX() << "," << from.getY() << " to " << to.getX() << "," << to.getY() << std::endl;  
  shared_ptr<Piece> piece = getSquare(from);
  // vector<Position> allMoves = piece->getAllMoves(make_shared<Chessboard>(*this), from);
  // bool foundLegalMove = false;
  // for (int i=0; i<allMoves.size(); i++) {
  //   if(to.getX() == allMoves[i].getX() && to.getY() == allMoves[i].getY()) {
  //     cout << "this move is legal " << endl;
  //     foundLegalMove = true;
  //   }
  //   Position p = allMoves[i];
  //   cout << p << "\n";
  // }
  // if(!foundLegalMove) {
  //   cout << "Throw illegal move exception" << endl; 
  // } else {
  //   placePiece(to, piece);
  //   clearSquare(from);
  // }
  placePiece(to, piece);
  clearSquare(from);
}

bool Chessboard::validNumberOfKings() const {
  int white = 0;
  int black = 0;
  for (int i=0; i<width; i++) {
    for (int j=0; j<width; j++) {
      shared_ptr<Piece> curr = board[i][j];
      // if (curr == nullptr) continue;
      if (curr && curr->getSymbol() == 'k') {
        if (curr->getTeam() == 'w') {
          white++;
        } else if (curr->getTeam() == 'b') {
          black++;
        }
      }
    }
  }
  // return true;
  return (white == 1 && black == 1);
}

bool Chessboard::validPawnPlacement() const {
  for (int i=0; i<width; i++) {
    shared_ptr<Piece> top = board[0][i];
    shared_ptr<Piece> bottom = board[0][i];
    if ((top && top->getSymbol() == 'p') || (bottom && bottom->getSymbol() == 'p')) {
      return false;
    }
  }
  return true;
}
