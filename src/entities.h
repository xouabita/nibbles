#ifndef ENTITIES_H
#define ENTITIES_H

#define EMPTY 0
#define NIBBLE 1
#define WALL 2
#define APPLE 3

#include <ncurses.h>

class Entity {
  char type;
  int x, y;
  public:
  Entity (char type, int x, int y);
  virtual void print () = 0;
  int getX ();
  int getY ();
  char getType ();
};

class Nibble : public Entity {
  public:
  Nibble (int x, int y);
  void print ();
};

class Wall : public Entity {
  public:
  Wall (int x, int y);
  void print ();
};

class Apple : public Entity {
  public:
  Apple (int x, int y);
  void print ();
};

#endif
