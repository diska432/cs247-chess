#ifndef RENDER_H
#define RENDER_H
#include <iostream>

class Chessboard;
class Position;

class Render {
  protected:
    // Ensure the memory and chessboard do not change in respect to the Render class
    const std::shared_ptr<Chessboard> const chessboard;
    // determine which team 
    bool isWhite(const Position& p) const;
  public:
    Render(std::shared_ptr<Chessboard> cb);
    virtual ~Render(); // virtual destructor to make it an abstract class
    virtual void render() = 0;
};

#endif
