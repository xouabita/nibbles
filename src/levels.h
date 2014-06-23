#ifndef LEVELS_H
#define LEVELS_H

#include "display.h"
#include "entities.h"
#include "player.h"
#include "gui.h"

class Level {
  protected:
  Window w;
  Menu menu_pause;
  Player plyr;
  public:
  Level (int x, int y);
  virtual void print () = 0;
  void start ();
};

class Level1 : public Level {
  public:
  Level1 ();
  void print ();
};

#endif
