#include "entities.h"

Entity::Entity (char t, int x, int y): type (t), x (x), y (y) {}
int Entity::getX () { return x; }
int Entity::getY () { return y; }
char Entity::getType () { return type; }

Nibble::Nibble (int x, int y): Entity (NIBBLE, x, y) {}
void Nibble::print() {
  attron(COLOR_PAIR(2));
  addch('O');
  refresh();
  attroff(COLOR_PAIR(2));
}

Wall::Wall (int x, int y): Entity (WALL, x, y) {}
void Wall::print() {
  attron(COLOR_PAIR(3));
  addch('#');
  refresh();
  attroff(COLOR_PAIR(3));
}

Apple::Apple (int x, int y): Entity (APPLE, x, y) {}
void Apple::print () {
  attron(COLOR_PAIR(4));
  addch('@');
  refresh();
  attroff(COLOR_PAIR(4));
}

NumberApple::NumberApple (int type, int x, int y) : Entity (type, x, y) {
  this->n = type - APPLE_1 + 49;
}

void NumberApple::print () {
  attron(COLOR_PAIR(4));
  addch(n);
  refresh();
  attroff(COLOR_PAIR(4));
}

