#include "display.h"

void initDisplay () {
  initscr ();
  start_color();
  cbreak(); // no line buffering
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  clear();
  flushinp();

  // Define colors for the game
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_RED);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLUE);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_RED, COLOR_YELLOW);
  init_pair(8, COLOR_YELLOW, COLOR_RED);
  init_pair(9, COLOR_BLUE, COLOR_RED);
}

void closeDisplay () { endwin(); }
