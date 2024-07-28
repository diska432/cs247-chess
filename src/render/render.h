#ifndef RENDER_H
#define RENDER_H
#include <iostream>

class Chessboard;
class Position;

class Render {
  protected:
    // Ensure the memory and chessboard do not change in respect to the Render class
    const Chessboard* const chessboard;
    // determine which team 
    bool isWhite(const Position& p) const;
  public:
    Render(Chessboard*);
    virtual ~Render(); // virtual destructor to make it an abstract class
    virtual void render() = 0;
};

#endif
