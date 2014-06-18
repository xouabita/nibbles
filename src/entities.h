#ifndef ENTITIES_H
#define ENTITIES_H

#define EMPTY 0
#define NIBBLE 1

#include <ncurses>

class Entity {
  int type, x, y;
  virtual void print () = 0;
  public:
  Entity (int type, int x, int y);
  int getX ();
  int getY ();
};

class Nibble : public Entity {
  public:
  Nibble (int x, int y);
};

#endif
