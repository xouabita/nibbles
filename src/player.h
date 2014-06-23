#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include "display.h"
#include "entities.h"
#include <iostream>
#include <queue>

void addApple (Window &w);

class Player {
  std::queue<Point> plyr;
  char dir;
  int grow;
  public:
  Player (int x, int y, Window & w);
  bool move (Window &w);
};

#endif
