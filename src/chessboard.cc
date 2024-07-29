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

void Chessboard::clearBoard() {
  for (int i=0; i<width; i++) {
    for (int j=0; j<width; j++) {
      board[i][j] = nullptr;
    }
  }
}

int Chessboard::getWidth() const { return width; };

Position Chessboard::getPotentialEnPassant() const { return potentialEnPassant; };

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

bool Chessboard::isValidMove(Position s, Position e) const {
  /*
  check if coordinate is in range
  check the move is valid based on the piece
  check if it puts king in check and shit
  */
  if (!positionInRange(s)) {
    cout << "Start position not on board\n";
    return false;
  }
  if (!positionInRange(e)) {
    cout << "End position not on board\n";
    return false;
  }

  shared_ptr<Piece> piece = getSquare(s);
  char type = piece->getSymbol();
  char team = piece->getTeam();

  if (piece == nullptr) {
    return false; // can't move something that doesn't exist
  }

  vector<Position> validMoves = piece->getAllMoves(make_shared<Chessboard>(*this), s);
  // if (type != 'r' || type != 'b' || type != 'n' || type != 'q' || type != 'p') {
  //   return true;
  // }
  if (find(validMoves.begin(), validMoves.end(), e) == validMoves.end()) {
    return false;
  }

  /*
  Add logic to check if the move will put the team's king in check
  */

  return true;
}

vector<shared_ptr<Position>> Chessboard::makeMove(Position from, Position to, char promotion) {
  std::cout << "Making move from " << from.getX() << "," << from.getY() << " to " << to.getX() << "," << to.getY() << std::endl;  
  vector<shared_ptr<Position>> res;
  res.push_back(make_shared<Position>(from));
  res.push_back(make_shared<Position>(to));
  shared_ptr<Piece> piece = getSquare(from);
  piece->setMoved(true);
  placePiece(to, piece);
  clearSquare(from);

  if (piece->getSymbol() == 'p') {
    // pawns are special
    // 1. en passant
    // 2. promotion
    Position pr = to - from;
    if (abs(pr.getX()) == 2 && pr.getY() == 0) {
      // directly up 2 or down 2
      potentialEnPassant = to;
    } else {
      if (pr.getY() != 0) {
        // diagonal movement type beat
        int yDiff = piece->getTeam() == 'w' ? -1 : 1;
        // if we are white, we want to capture when 
        // black moves down and vice versa
        Position enPassant = to + Position{yDiff, 0};
        if (enPassant == potentialEnPassant) {
          clearSquare(enPassant);
          res.push_back(make_shared<Position>(enPassant));
        }
      }
      potentialEnPassant = Position{-1, -1};
    }

    // promotion
    if (piece->getTeam() == 'w' && to.getX() == 7 ||
        piece->getTeam() == 'b' && to.getX() == 0) {
      // this is a pawn that is now located on a back rank
      shared_ptr<Piece> promotedPawn;
      switch (promotion) {
        case 'q':
          promotedPawn = make_shared<Queen>(piece->getTeam());
          break;
        case 'r':
          promotedPawn = make_shared<Rook>(piece->getTeam());
          break;
        case 'b':
          promotedPawn = make_shared<Bishop>(piece->getTeam());
          break;
        case 'n':
          promotedPawn = make_shared<Knight>(piece->getTeam());
          break;
        default:
          clearSquare(to);
          placePiece(from, piece);
          throw InvalidPromotionException();
      }
      placePiece(to, promotedPawn);
    }
  }

  if (piece->getSymbol() != 'p') {
    potentialEnPassant = Position{-1, -1};
  }

  return res;
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
