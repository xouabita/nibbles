#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <iostream>
#include <queue>
#include "entities.h"
#include "display.h"
#include "gui.h"
#include "player.h"
#include "levels.h"

#define EXIT 0
#define LOOSE 1
#define WIN 2

class Game {
  Window w;
  Menu menu_pause;
  public:
  Game (Level * l);
  void start ();
};

#endif
