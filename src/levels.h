#ifndef LEVELS_H
#define LEVELS_H

#include "display.h"
#include "entities.h"
#include "player.h"
#include "gui.h"

#include <iostream>

class Level {
  protected:
  Window w;
  Menu menu_pause;
  Player plyr;
  int apple;
  void addApple ();
  public:
  Level (int x, int y);
  virtual void print () = 0;
  int start ();
};

class Level1 : public Level {
  public:
  Level1 ();
  void print ();
};

class Level2 : public Level {
  public:
  Level2 ();
  void print ();
};


class Level3 : public Level {
  public:
  Level3 ();
  void print ();
};

class Level4 : public Level {
  public:
  Level4 ();
  void print ();
};

/*
class Level5 : public Level {
  public:
  Level5 ();
  void print ();
};

class Level6 : public Level {
  public:
  Level6 ();
  void print ();
};

class Level7 : public Level {
  public:
  Level7 ();
  void print ();
};
*/
#endif
