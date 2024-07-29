#include "exception.h"

const char* InvalidMoveException::what() const throw () {
  return "Invalid move.";
}

const char* NotInSetupModeException::what() const throw () {
  return "Not in setup mode.";
}
