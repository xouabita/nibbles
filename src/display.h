#ifndef DISPLAY_H
#define DISPLAY_H
#include <ncurses.h>
#include "entities.h"

#define WIDTH 80
#define HEIGHT 50

// Init a new display by configuring ncurses
void initDisplay();

// Close ncurses
void closeDisplay();

class Window {

  char[HEIGHT][WIDTH] array;
  public:
  Window ();
};

#endif
