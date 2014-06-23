#include <iostream>
#include <ncurses.h>
#include <string>
#include "display.h"
#include "gui.h"
#include "entities.h"
#include "levels.h"

void displayLife (int n) {
  std::string lifes = "Life: ";
  lifes += (n+48);
  move (HEIGHT,0);
  printw(lifes.c_str());
  refresh();
}

int launchLevel (int i, int lifes) {
  Level * l;
  switch (i) {
    case 0:
      l = new Level1 ();
      break;
    case 1:
      l = new Level2 ();
      break;
    case 2:
      l = new Level3 ();
      break;
    case 3:
      l = new Level4 ();
      break;
  }
  clear();
  l->print();
  displayLife (lifes);
  int res = l->start();
  delete l;
  return res;
}

void launchSingleplayer () {
  int number_levels = 4;
  int lifes = 5;

  Menu stageComplete_menu;
  stageComplete_menu.addItem ( new Title ("Stage Complete !!!!") );
  stageComplete_menu.addItem ( new Blank () );
  stageComplete_menu.addItem ( new Button ("Continue",0));
  stageComplete_menu.addItem ( new Button ("Exit", 1));

  Menu win_menu;
  win_menu.addItem (new Title ("You Win !!!"));
  win_menu.addItem (new Blank () );
  win_menu.addItem (new Button ("Exit", 0));

  Menu life_menu;
  life_menu.addItem (new Error ("You loose a life"));
  life_menu.addItem (new Blank () );
  life_menu.addItem (new Button ("Retry", 0));
  life_menu.addItem (new Button ("Exit", 1));

  Menu loose_menu;
  loose_menu.addItem (new Error ("You loose the game !!!"));
  loose_menu.addItem (new Blank () );
  loose_menu.addItem (new Button ("Exit", 0));

  int i = 0;
  bool exit = false;

  while (!exit) {
    int res = launchLevel (i, lifes);
    switch (res) {
      case EXIT:
        exit = true;
        break;
      case WIN:
        if (i == number_levels-1) {
          win_menu.draw();
          win_menu.getSelect();
          exit = true;
        } else {
          stageComplete_menu.draw();
          int s = stageComplete_menu.getSelect();
          if (s == 1) exit = true;
          else i++;
        }
        break;
      case LOOSE:
        lifes--;
        if (lifes == 0) {
          exit = true;
          loose_menu.draw();
          loose_menu.getSelect();
        } else {
          life_menu.draw();
          int s = life_menu.getSelect();
          if (s != 0) {
            exit = true;
          }
        }
        break;
    }
  }
}

void launchMultiplayer () {

  Menu win_menu;
  win_menu.addItem (new Title ("You Win !!!"));
  win_menu.addItem (new Blank () );
  win_menu.addItem (new Button ("Replay", 0));
  win_menu.addItem (new Button ("Exit", 1));

  Menu loose_menu;
  loose_menu.addItem (new Error ("You loose the game !!!"));
  loose_menu.addItem (new Blank () );
  loose_menu.addItem (new Button ("Retry", 0));
  loose_menu.addItem (new Button ("Exit", 1));

  bool exit = false;

  while (!exit) {
    MultiLevel l;
    clear();
    l.print();
    int res = l.start();
    switch (res) {
      case EXIT:
        exit = true;
        break;
      case WIN:
        win_menu.draw();
        exit = win_menu.getSelect();
        break;
      case LOOSE:
        loose_menu.draw();
        exit = loose_menu.getSelect();
        break;
    }
  }
}


void mainMenu () {
  Menu my_box (50);
  my_box.addItem (new Blank ());
  my_box.addItem (new Title ("Ooooo Nibbles ooooO"));
  my_box.addItem (new Blank ());
  my_box.addItem (new Blank ());
  my_box.addItem (new Button ("Single Player",0));
  my_box.addItem (new Button ("Multi Player",1));
  my_box.addItem (new Button ("Exit",2));
  my_box.addItem (new Blank ());

  bool end = false;
  while (!end) {
    clear();
    my_box.draw ();
    int n = my_box.getSelect ();
    switch (n) {
      case 0:
        launchSingleplayer ();
        break;
      case 1:
        launchMultiplayer ();
        break;
      default:
        end = true;
        break;
    }
  }
}

int main () {

  initDisplay ();
  int win_height, win_width;
  getmaxyx(stdscr, win_height, win_width);
  if (win_width < WIDTH || win_height < HEIGHT+1) {
    closeDisplay ();
    std::cout << "width: " << win_width << ", height: " << win_height << std::endl;
    std::cout << "Your window is too small. Resize it" << std::endl;
    return 1;
  }
  mainMenu();
  closeDisplay ();
  return 0;
}
