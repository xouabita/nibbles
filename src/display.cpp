#include "display.h"

void initDisplay () {
  initscr ();
  start_color();
  cbreak(); // no line buffering
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  curs_set(0);
  clear();
  flushinp();

  // Define colors for the game
  init_pair(1, COLOR_WHITE, COLOR_BLACK); // Background
  init_pair(2, COLOR_YELLOW, COLOR_BLACK); // Nibble color
  init_pair(3, COLOR_WHITE, COLOR_BLUE); // Wall color
  init_pair(4, COLOR_YELLOW, COLOR_RED); // Apple Color
  init_pair(5, COLOR_WHITE, COLOR_BLUE);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_RED, COLOR_YELLOW);
  init_pair(8, COLOR_RED, COLOR_BLACK);   // Error message
  init_pair(9, COLOR_GREEN, COLOR_BLACK); // Title message

}

void closeDisplay () {
  endwin();
  keypad(stdscr, FALSE);
  nodelay(stdscr, FALSE);
  curs_set(1);
}

Window::Window () {
  array = new char* [HEIGHT];
  for (int i=0; i<HEIGHT; i++) {
    array[i] = new char [WIDTH];
    for (int j=0; j<WIDTH; j++) {
      array[i][j] = NULL;
    }
  }
}

Window::~Window () {
  for (int i=0; i<HEIGHT; i++) {
    delete [] array[i];
  }
  delete [] array;
}

void Window::setEntity (Entity * e) {
  array[e->getY()][e->getX()] = e->getType();
  move(e->getY(), e->getX());
  e->print();
  delete e;
}

void Window::delEntity (int x, int y) {
  move(y,x);
  addch(' ');
  array[y][x] = EMPTY;
}

char Window::getEntity (int x, int y) {
  return array[y][x];
}

void Window::refresh () {
  clear();
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (array[i][j]) {
        move(i,j);
        Entity * e;
        switch (array[i][j]) {
          case WALL:
            e = new Wall (j,i);
            break;
          case NIBBLE:
            e = new Nibble (j,i);
            break;
          case APPLE:
            e = new Apple (j,i);
            break;
          default:
            e = new NumberApple (array[i][j], j, i);
            break;
        }
        e->print ();
        delete e;
      }
    }
  }
}
