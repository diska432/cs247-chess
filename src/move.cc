#include "move.h"
#include "position.h"
#include "piece/piece.h"
#include <stack>

using namespace std;

// Move class constructor
AtomicMove::Move::Move(char type, char team, shared_ptr<Piece> piece, Position p1, Position p2) : 
  type(type), team(team), piece(piece), p1(p1), p2(p2) {};

AtomicMove::AtomicMove() {};

void AtomicMove::addMove(char type, char team, shared_ptr<Piece> piece, Position p1, Position p2) {
  AtomicMove::Move currentMove = AtomicMove::Move(type, team, piece, p1, p2);
  moveStack.push(currentMove);
}
