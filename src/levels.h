#ifndef LEVELS_H
#define LEVELS_H

#include "display.h"
#include "entities.h"

class Level {
  public:
  virtual void print (Window & w) = 0;
};

class Level1 : public Level {
  public:
  void print (Window &w);
};

#endif
