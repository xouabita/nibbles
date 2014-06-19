#include <iostream>
#include <ncurses.h>
#include "game.h"
#include "display.h"
#include "entities.h"
#include "levels.h"

int main () {

  initDisplay ();
  int win_height, win_width;
  getmaxyx(stdscr, win_height, win_width);
  if (win_width < WIDTH || win_height < HEIGHT) {
    closeDisplay ();
    std::cout << "width: " << win_width << ", height: " << win_height << std::endl;
    std::cout << "Your window is too small. Resize it" << std::endl;
    return 1;
  }

  Game g (new Level1 ());
  g.start();

  closeDisplay ();

  return 0;
}
