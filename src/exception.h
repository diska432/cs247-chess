#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <stdexcept>
#include "position.h"

class InvalidMoveException : public std::exception {
  virtual const char* what() const throw();
};

#endif
