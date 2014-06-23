#ifndef ENTITIES_H
#define ENTITIES_H

#define EMPTY 0
#define NIBBLE 1
#define WALL 2
#define APPLE 3
#define APPLE_1 4
#define APPLE_2 5
#define APPLE_3 6
#define APPLE_4 7
#define APPLE_5 8
#define APPLE_6 9
#define APPLE_7 10

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

class NumberApple : public Entity {
  char n;
  public:
  NumberApple (int type, int x, int y);
  void print ();
};

#endif
