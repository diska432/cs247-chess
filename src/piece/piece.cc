#include "piece.h"
#include "../position.h"

using namespace std;

Piece::Piece(char symbol, char team) : symbol(symbol), team(team) {};

char Piece::getSymbol() const {
  return symbol;
}

char Piece::getTeam() const {
  return team;
}
