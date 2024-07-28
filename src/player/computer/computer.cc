#include "computer.h"
#include <memory>

using namespace std;

Computer::Computer(shared_ptr<Chessboard> chessboard) : chessboard(chessboard) {
  isHuman = false; // it's a computer lol
}
