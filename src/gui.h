#ifndef GUI_H
#define GUI_H

#include "display.h"
#include <iostream>
#include <vector>
#include <ncurses.h>

#define CORNER '*'
#define LINE   '-'
#define COLUMN '|'

class Box {
  protected:
  int height, width;
  Point pos;
  virtual void drawBox ();
  public:
  Box (int x, int y, int w, int h);
  virtual void draw ();
};

struct Item {
  int w;
  virtual void print () = 0;
};

class Label : public Item {
  std::string text;
  public:
  Label (std::string t);
  virtual void print ();
};

class StackBox : public Box {
  std::vector<Item*> items;
  int max_width;
  public:
  StackBox();
  void addItem (Item * i);
  void draw ();
  ~StackBox();
};

#endif
