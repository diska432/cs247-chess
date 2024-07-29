#include "level1.h"
#include <cstdlib> 
#include <iostream>
#include <ctime>

using namespace std;

Level1::Level1(shared_ptr<Chessboard> chessboard, char color) : Computer(chessboard) {
  this->color = color;
}

pair<Position, Position> Level1::getMove() {
  Position p;
  vector<pair<Position, Position>> valid_moves;

  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
        Position q{i, j};
        shared_ptr<Piece> piece = chessboard->getSquare(q);

        if (piece != nullptr && piece->getTeam() == color) {
          vector<Position> moves = piece->getAllMoves(chessboard, q);
          for (Position move : moves) {
              valid_moves.push_back(make_pair(q, move));
          }
        }

    }
  }

  for (auto move : valid_moves) {
    Position from = move.first;
    Position to = move.second;
    cout << from.toString()  << " | " << to.toString() << endl;
  }
  
  srand(time(0));
  int random_variable = (rand() % valid_moves.size());
  
  return valid_moves[random_variable];
}