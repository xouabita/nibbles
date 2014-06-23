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
  bool canSelect;
  int return_value;
  virtual void print    () = 0;
  virtual void onSelect () = 0;
};

class Label : public Item {
  protected:
  std::string text;
  public:
  Label (std::string t);
  virtual void print ();
  void onSelect ();
};

class Blank : public Label {
  public:
  Blank ();
};

class Title : public Label {
  public:
  Title (std::string t);
  void print ();
};

class Error : public Label {
  public:
  Error (std::string t);
  void print ();
};

class StackBox : public Box {
  protected:
  std::vector<Item*> items;
  int max_width;
  public:
  StackBox(int w = 0);
  virtual void addItem (Item * i);
  void draw ();
  virtual ~StackBox();
};

class Button : public Item {
  std::string text;
  public:
  Button (std::string t, int r);
  virtual void print ();
  virtual void onSelect ();
};

class Menu : public StackBox {
  int vect_pos;
  std::vector<int> selections;
  void mv_curs (int i);
  void applySelect ();
  void applyDeselect ();
  void Up ();
  void Down ();
  public:
  Menu (int w = 0);
  void draw ();
  void addItem (Item * i);
  int getSelect ();
};

#endif
