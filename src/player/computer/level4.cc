#include "level4.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <map>

using namespace std;

Level4::Level4(shared_ptr<Chessboard> chessboard, char color) : Computer(chessboard) {
  this->color = color;
}

int Level4::weighOutcomes() {
  map<pair<pair<Position, Position>, Position>, int> second_order_moves; // start loc, loc 2 away
  map<pair<Position, Position>, int> weighted_capture_moves;

  map<char, int> piece_values = {
    {'p', 1},
    {'r', 5},
    {'n', 3},
    {'b', 3},
    {'q', 10},
    {'k', 100}
  };

  int oppValue = 0;
  int myValue = 0;
  vector<pair<shared_ptr<Piece>, Position>> my_pieces;
  vector<pair<shared_ptr<Piece>, Position>> opponent_pieces;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      Position q{i, j};
      shared_ptr<Piece> piece = chessboard->getSquare(q);

      if (piece != nullptr) {
        if (piece->getTeam() == color) {
          myValue += piece_values[piece->getSymbol()];
          my_pieces.push_back(make_pair(piece, q));
        } else {
          oppValue += piece_values[piece->getSymbol()];
          opponent_pieces.push_back(make_pair(piece, q));
        }
      }
    }
  }

  for (auto opiece : opponent_pieces) {
    shared_ptr<Piece> piece = opiece.first;
    Position q = opiece.second;

    vector<Position> moves = piece->getAllMoves(chessboard, q);

     for (Position move : moves) {
      int currentVal = myValue - oppValue; 
      if (chessboard->getSquare(move) != nullptr) {
        if (chessboard->isValidMove(q, move)) {
          weighted_capture_moves[make_pair(q, move)] = (currentVal - piece_values[chessboard->getSquare(move)->getSymbol()]);
          currentVal -= piece_values[chessboard->getSquare(move)->getSymbol()];
        }
      }
      for (auto mpiece : my_pieces) {
        shared_ptr<Piece> piece2 = mpiece.first;
        Position move = mpiece.second;
        vector<Position> sMoves = piece->getAllMoves(chessboard, move);

          for (Position sMove : sMoves) {
            if (chessboard->isValidMove(q, move) && chessboard->isValidMove(move, sMove)) {
              if (chessboard->getSquare(sMove) != nullptr) {
                currentVal += piece_values[chessboard->getSquare(sMove)->getSymbol()];
              }
              second_order_moves[make_pair(make_pair(q, move), sMove)] = currentVal;
            }
          }
        }
     }

  }

  int minWeight = myValue - oppValue;
  for (auto it = weighted_capture_moves.begin(); it != weighted_capture_moves.end(); ++it) {
    if (it->second < minWeight) {
      minWeight = it->second;
    }
  }

  int minSOrder = myValue - oppValue;
  for (auto it = second_order_moves.begin(); it != second_order_moves.end(); ++it) {
    if (it->second < minSOrder) {
      minSOrder = it->second;
    }
  }

  return minWeight + minSOrder;
}

pair<Position, Position> Level4::getMove() {
  vector<pair<Position, Position>> valid_moves; // start loc, end loc

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      Position q{i, j};
      shared_ptr<Piece> piece = chessboard->getSquare(q);

      if (piece != nullptr && piece->getTeam() == color) {
        vector<Position> moves = piece->getAllMoves(chessboard, q);
        for (Position move : moves) {
          if (chessboard->isValidMove(q, move)) {
            valid_moves.push_back(make_pair(q, move));
          }
        }
      }
    }
  }

  vector<pair<Position, Position>> minimized_moves;
  int minOutcome = INT_MIN;

  for (auto move : valid_moves) {
    auto from = chessboard->getSquare(move.first);
    auto to = chessboard->getSquare(move.second);
    chessboard->clearSquare(move.first);
    chessboard->placePiece(move.second, from);

    int outcome = weighOutcomes();

    if (outcome == minOutcome) {
      minimized_moves.push_back(move);
    } else if (outcome > minOutcome) {
      minOutcome = outcome;
      minimized_moves.clear();
      minimized_moves.push_back(move);
    }

    cout << "From: " << move.first.toString() << " To: " << move.second.toString() << " : " << minOutcome << endl;

    chessboard->clearSquare(move.second);
    chessboard->placePiece(move.first, from);
    chessboard->placePiece(move.second, to);
  }

  // cout << "Minimized Moves:" << endl;
  // for (auto move : minimized_moves) {
  //   cout << "From: " << move.first.toString() << " To: " << move.second.toString() << " : " << minOutcome << endl;
  // }
     

  srand(time(0));
  int random_variable = (rand() % minimized_moves.size());
  return minimized_moves[random_variable];
}