#include "gui.h"

Box::Box (int x, int y, int w, int h): height (h), width (w), pos (x,y) {}

void Box::drawBox () {

  for (int i=pos.y; i < pos.y+height-1; i++) {
    for (int j=pos.x; j < pos.x+width-1; j++) {
      move(i,j);
      addch(' ');
    }
  }

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
  text      = t;
  w         = text.length();
  canSelect = false;
}

void Label::print () {
  printw(text.c_str());
}

void Label::onSelect () {}

Blank::Blank () : Label ("") {}

Title::Title (std::string t) : Label (t) {}
void Title::print () {
  attron(COLOR_PAIR (9));
  attron(A_BOLD);
  attron(A_DIM);
  printw(text.c_str());
  attroff(COLOR_PAIR (9));
  attroff(A_BOLD);
  attroff(A_DIM);
}

Error::Error (std::string t) : Label (t) {}
void Error::print () {
  attron(COLOR_PAIR (8));
  attron(A_BOLD);
  attron(A_DIM);
  printw(text.c_str());
  attroff(COLOR_PAIR (8));
  attroff(A_BOLD);
  attroff(A_DIM);
}

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

Button::Button (std::string t, int r ) {
  text         = t;
  return_value = r;
  w            = text.length ();
  canSelect    = true;
}

void Button::print () {
  printw (text.c_str());
}

void Button::onSelect () {
  attron (A_REVERSE);
  printw (text.c_str ());
  attroff (A_REVERSE);
}

Menu::Menu (int w) : StackBox (w) {
  vect_pos = 0;
}

void Menu::draw () {
  StackBox::draw ();
  applySelect ();
  refresh();
}

void Menu::addItem (Item * i) {
  StackBox::addItem (i);
  if (i->canSelect) {
    selections.push_back ( items.size() - 1 );
  }
}

void Menu::mv_curs (int i) {
  int y = pos.y + 1 + i;
  int x = pos.x + width/2 - items[i]->w/2;
  move(y,x);
}

void Menu::applySelect () {
  if (vect_pos >= 0) {
    int i = selections[vect_pos];
    mv_curs (i);
    items[i]->onSelect();
    refresh ();
  }
}

void Menu::applyDeselect () {
  int i = selections[vect_pos];
  mv_curs (i);
  items[i]->print();
}

void Menu::Up () {
  applyDeselect ();
  if ( vect_pos != 0) {
    vect_pos--;
  } else {
    vect_pos = selections.size()-1;
  }
  applySelect ();
  refresh ();
}

void Menu::Down () {
  applyDeselect ();
  if ( vect_pos != selections.size()-1 ) {
    vect_pos++;
  } else {
    vect_pos = 0;
  }
  applySelect ();
  refresh ();
}

int Menu::getSelect () {
  nodelay(stdscr, FALSE);
  int c = getch();
  while (c != '\n') {
    switch (c) {
      case KEY_UP:
        this->Up();
        break;
      case KEY_DOWN:
        this->Down();
        break;
    }
    c = getch();
  }
  nodelay(stdscr, TRUE);
  return items[ selections[vect_pos] ]->return_value ;
}
