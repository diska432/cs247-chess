#include "level2.h"
#include <cstdlib> 
#include <iostream>
#include <ctime>
#include <map>

using namespace std;

Level2::Level2(shared_ptr<Chessboard> chessboard, char color) : Computer(chessboard) {
  this->color = color;
}

pair<Position, Position> Level2::getMove() {
  Position p;
  vector<pair<Position, Position>> valid_moves; // start loc, end loc
  vector<pair<pair<Position, Position>, Position>> second_order_moves; // start loc, loc 2 away
  vector<pair<Position, Position>> capture_moves;

  vector<Position> opponent_pieces;
  Position king_position;

  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
        Position q{i, j};
        shared_ptr<Piece> piece = chessboard->getSquare(q);

        if (piece != nullptr && piece->getTeam() == color) {
          vector<Position> moves = piece->getAllMoves(chessboard, q);
          for (Position move : moves) {
              if (chessboard->isValidMove(q, move)) {
                valid_moves.push_back(make_pair(q, move));
              }

              if (chessboard->getSquare(move) != nullptr) {
                if (chessboard->isValidMove(q, move)) {
                  capture_moves.push_back(make_pair(q, move));
                }
              }
              
              vector<Position> sMoves = piece->getAllMoves(chessboard, move);
              for (Position sMove : sMoves) {
                if (chessboard->isValidMove(q, move) && chessboard->isValidMove(move, sMove)) {
                  second_order_moves.push_back(make_pair(make_pair(q, move), sMove));
                }
              }  
             
          }
        }
        else if (piece != nullptr && piece->getTeam() != color) {
          if (piece->getSymbol() == 'k') {
            king_position = q;
          } 
          opponent_pieces.push_back(q);
        }

    }
  }

  srand(time(0));

  // prefer checks
  vector<pair<Position, Position>> check_move;

  for (auto move : second_order_moves) {
    if (move.second == king_position) {
      check_move.push_back(move.first);
    }
  }

  if (check_move.size() > 0) {
    int random_variable = (rand() % check_move.size());
    return check_move[random_variable];
  }

  // prefer captures

  if (capture_moves.size() > 0) {
    int random_variable = (rand() % capture_moves.size());
    return capture_moves[random_variable];
  }

  int random_variable = (rand() % valid_moves.size());
  return valid_moves[random_variable];
}