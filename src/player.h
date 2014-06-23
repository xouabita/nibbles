#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include "display.h"
#include "entities.h"
#include <iostream>
#include <queue>

#define NOTHING 0
#define LOOSE   1
#define PAUSE   2
#define EAT     3
#define EXIT    4
#define WIN     5

class Player {
  std::queue<Point> plyr;
  char dir;
  int gr;
  public:
  Player (int x, int y, Window & w);
  int move (Window &w);
  void grow (int g);
};

#endif
