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

  Window w;
  Player p (10,10,w);
  Level1 l;
  l.print(w);
  int c = getch();
  while (c != ' ') {
    usleep(500000);
    p.move(w);
    c = getch();
  }

  closeDisplay ();

  return 0;
}
