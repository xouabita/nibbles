#ifndef DISPLAY_H
#define DISPLAY_H
#include <ncurses.h>
#include "entities.h"

#define WIDTH 80 // Width of the window
#define HEIGHT 25 // Height of the window

// Point in an array
struct Point {
  int x,y;
  Point (int m_x, int m_y): x (m_x), y (m_y) {}
};

// Init a new display by configuring ncurses
void initDisplay();

// Close ncurses
void closeDisplay();

// Represent the window
class Window {

  char array[HEIGHT][WIDTH]; // Array with entity
  public:
  Window ();
  void setEntity (Entity * e);
  void delEntity (int x, int y);
  char getEntity (int x, int y);
};

#endif
