#include <iostream>
#include <ncurses.h>
#include "game.h"
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

  /*Game g (new Level1 ());
  g.start(); */

  StackBox my_box ( 60 );
  my_box.addItem (new Blank ());
  my_box.addItem (new Label ("My super title"));
  my_box.addItem (new Blank ());
  my_box.addItem (new Blank ());
  my_box.addItem (new Label ("Single Player"));
  my_box.addItem (new Label ("Multi Player"));
  my_box.addItem (new Label ("Exit"));
  my_box.addItem (new Blank ());
  my_box.draw ();

  sleep (10);

  closeDisplay ();

  return 0;
}
