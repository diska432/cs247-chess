#include "level3.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <map>

using namespace std;

Level3::Level3(shared_ptr<Chessboard> chessboard, char color) : Computer(chessboard)
{
  this->color = color;
}

int Level3::weighOutcomes()
{
  vector<pair<pair<Position, Position>, Position>> second_order_moves; // start loc, loc 2 away
  vector<pair<Position, Position>> capture_moves;

  int checkMoves = 0;

  vector<Position> my_pieces;
  Position king_position;

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      Position q{i, j};
      shared_ptr<Piece> piece = chessboard->getSquare(q);

      if (piece != nullptr && piece->getTeam() != color)
      {

        vector<Position> moves = piece->getAllMoves(chessboard, q);
        for (Position move : moves)
        {
          if (chessboard->getSquare(move) != nullptr)
          {
            capture_moves.push_back(make_pair(q, move));
          }

          vector<Position> sMoves = piece->getAllMoves(chessboard, move);

          for (Position sMove : sMoves)
          {
            second_order_moves.push_back(make_pair(make_pair(q, move), sMove));
          }
        }
      }
      else if (piece != nullptr && piece->getTeam() == color)
      {
        if (piece->getSymbol() == 'k')
        {
          king_position = q;
        }
        my_pieces.push_back(q);
      }


    }
  }
  for (auto move : second_order_moves) {
    if (move.second == king_position) {
      checkMoves++;
    }
  }

  return checkMoves*3 + capture_moves.size()*10;
}

pair<Position, Position> Level3::getMove()
{
  vector<pair<Position, Position>> valid_moves; // start loc, end loc

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      Position q{i, j};
      shared_ptr<Piece> piece = chessboard->getSquare(q);

      if (piece != nullptr && piece->getTeam() == color)
      {
        vector<Position> moves = piece->getAllMoves(chessboard, q);
        for (Position move : moves)
        {
          valid_moves.push_back(make_pair(q, move));
        }
      }
    }
  }

  vector<pair<Position, Position>> minimized_moves;
  int minOutcome = INT_MAX;

  for (auto move : valid_moves)
  {
    auto from = chessboard->getSquare(move.first);
    auto to = chessboard->getSquare(move.second);
    chessboard->clearSquare(move.first);
    chessboard->placePiece(move.second, from);

    int outcome = weighOutcomes();

    if (outcome == minOutcome) {
      minimized_moves.push_back(move);
    } else if (outcome < minOutcome) {
      minOutcome = outcome;
      minimized_moves.clear();
      minimized_moves.push_back(move);
    }

    chessboard->clearSquare(move.second);
    chessboard->placePiece(move.first, from);
    chessboard->placePiece(move.second, to);


  }

  cout << "minOutcome: " << minOutcome << endl;
  cout << "minimized_moves: ";
  for (auto move : minimized_moves) {
    cout << "(" << move.first.toString() << ") -> (" << move.second.toString() << ") ";
  }
  cout << endl;

  srand(time(0));
  int random_variable = (rand() % minimized_moves.size());
  return minimized_moves[random_variable];
}