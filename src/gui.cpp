#include "gui.h"

Box::Box (int x, int y, int w, int h): height (h), width (w), pos (x,y) {}

void Box::drawBox () {
  // Draw the corners
  move(pos.y, pos.x);
  addch(CORNER);
  move(pos.y, pos.x+width-1);
  addch(CORNER);
  move(pos.y+height-1,pos.x);
  addch(CORNER);
  move(pos.y+height-1,pos.x+width-1);
  addch(CORNER);

  // Draw columns and lines
  for (int i=pos.x+1; i < pos.x+width-1; i++) {
    move(pos.y, i);
    addch(LINE);
    move(pos.y+height-1,i);
    addch(LINE);
  }
  for (int i=pos.y+1; i < pos.y+height-1; i++) {
    move(i,pos.x);
    addch(COLUMN);
    move(i,pos.x+width-1);
    addch(COLUMN);
  }

  refresh();
}

void Box::draw () {
  this->drawBox();
}

Label::Label (std::string t) {
  text = t;
  w    = text.length();
}

void Label::print () {
  printw(text.c_str());
}

Blank::Blank () : Label ("") {}

StackBox::StackBox (int w) : Box (WIDTH/2-2,HEIGHT/2-2,w+4,2) {
  max_width = w;
}
StackBox::~StackBox () {
  for (unsigned int i=0; i < items.size(); i++) {
    delete items[i];
  }
}

void StackBox::addItem (Item * i) {
  items.push_back (i);
  if (i->w > max_width) {
    width += (i->w - max_width);
    max_width = i->w;
  }

  height += 1;

  pos.x = WIDTH/2 - width/2;
  pos.y = HEIGHT/2 - height/2;
}

void StackBox::draw () {
  this->drawBox ();
  for (unsigned int i=0; i < items.size(); i++) {
    int y = pos.y + 1 + i;
    int x = pos.x + width/2 - items[i]->w/2;
    move(y,x);
    items[i]->print();
  }
  refresh();
}
