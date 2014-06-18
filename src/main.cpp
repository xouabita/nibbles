#include <iostream>
#include <ncurses.h>
#include "display.h"

int main () {
  int win_height, win_width;
  getmaxyx(stdscr, win_height, win_width);
  if (win_width < WIDTH || win_height < HEIGHT) {
    std::cout << "Your window is too small. Resize it" << std::endl;
    return 1;
  }
  return 0;
}
