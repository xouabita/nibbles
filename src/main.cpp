#include <iostream>
#include <ncurses.h>
#include "display.h"
#include "gui.h"
#include "entities.h"
#include "levels.h"

void launchMultiplayer () {}
void launchSingleplayer () {}

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

  Menu my_box (50);
  my_box.addItem (new Blank ());
  my_box.addItem (new Title ("Ooooo Nibbles ooooO"));
  my_box.addItem (new Blank ());
  my_box.addItem (new Blank ());
  my_box.addItem (new Button ("Single Player",0));
  my_box.addItem (new Button ("Multi Player",1));
  my_box.addItem (new Button ("Exit",2));
  my_box.addItem (new Blank ());
  my_box.draw ();
  int n = my_box.getSelect ();

  switch (n) {
    case 0:
      clear();
      Level * l = new Level1 ();
      l->print();
      l->start();
      delete l;
      break;
  }

  closeDisplay ();

  std::cout << n << std::endl;

  return 0;
}
