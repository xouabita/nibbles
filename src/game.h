#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <iostream>
#include <queue>
#include "entities.h"
#include "display.h"

class Player {
  std::queue<Point> plyr;
  char dir;
  public:
  Player (int x, int y, Window & w);
  void move (Window &w);
};

class Game {
  
};

#endif
