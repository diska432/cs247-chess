#include "render.h"
#include "../chessboard.h"
#include "../position.h"

using namespace std;

Render::Render(shared_ptr<Chessboard> chessboard) : chessboard(chessboard) {};

Render::~Render() {};

bool Render::isWhite(const Position &p) const {
  // black squares are when the x%2=y%2
  if (p.getX() % 2 == p.getY() % 2) {
    return false; 
  }
  return true;
}
