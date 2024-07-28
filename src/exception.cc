#include "exception.h"

const char* InvalidMoveException::what() const throw () {
  return "Invalid move.";
}
