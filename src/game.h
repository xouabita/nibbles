#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <iostream>
#include <queue>
#include "entities.h"
#include "display.h"
#include "levels.h"

class Player {
  std::queue<Point> plyr;
  char dir;
  public:
  Player (int x, int y, Window & w);
  bool move (Window &w);
};

class Game {
  Window w;
  public:
  Game (Level * l);
  void start ();
};

#endif
