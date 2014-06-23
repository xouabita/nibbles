#include "levels.h"

Level::Level (int x, int y) : plyr (x,y,w) {

  // Pause Menu
  menu_pause.addItem (new Label ("    Pause     "));
  menu_pause.addItem (new Blank ());
  menu_pause.addItem (new Button ("Continue",0));
  menu_pause.addItem (new Button ("Exit", 1));

  apple = APPLE_1;
}

void Level::addApple () {
  srand(time(NULL));
  unsigned int x = rand() % (WIDTH-1);
  unsigned int y = rand() % (HEIGHT-1);
  if (w.getEntity(x,y) == EMPTY) {
    w.setEntity (new NumberApple (apple,x,y));
  } else {
    usleep(50);
    addApple();
  }
}

int Level::start () {
  addApple();
  while (1) {
    int plyr_res = plyr.move(w);
    if (plyr_res == PAUSE) {
      menu_pause.draw();
      int res = menu_pause.getSelect();
      if (res) { return EXIT; }
      else { w.refresh(); }
    }
    else if (plyr_res == EAT) {
      if (apple == APPLE_7) return WIN;
      else {
        plyr.grow (((apple - APPLE_1 + 1) * 5)-1);
        apple++;
        addApple();
      }
    }
    else if (plyr_res == LOOSE) {
      return LOOSE;
    }
    usleep(110000);
  }
}

Level1::Level1 () : Level (10,10) {}

void Level1::print() {
  for (int i = 0; i < WIDTH; i++) {
    w.setEntity(new Wall (i,0));
    w.setEntity(new Wall (i, HEIGHT-1));
  }

  for (int i = 0; i < HEIGHT; i++) {
    w.setEntity(new Wall (0,i));
    w.setEntity(new Wall (WIDTH-1,i));
  }
  refresh();
}

Level2::Level2 () : Level (WIDTH/2, HEIGHT-10) {}
void Level2::print() {
  for (int i = 0; i < WIDTH; i++) {
    w.setEntity(new Wall (i,0));
    w.setEntity(new Wall (i, HEIGHT-1));
  }

  for (int i = 0; i < HEIGHT; i++) {
    w.setEntity(new Wall (0,i));
    w.setEntity(new Wall (WIDTH-1,i));
  }

  for (int i = 10; i < WIDTH - 10; i++) {
    w.setEntity(new Wall (i, HEIGHT/2));
  }
  refresh();
}

Level3::Level3 () : Level (WIDTH-5, HEIGHT/2) {}
void Level3::print() {
  for (int i = 0; i < WIDTH; i++) {
    w.setEntity(new Wall (i,0));
    w.setEntity(new Wall (i, HEIGHT-1));
  }

  for (int i = 0; i < HEIGHT; i++) {
    w.setEntity(new Wall (0,i));
    w.setEntity(new Wall (WIDTH-1,i));
  }

  for (int i = 5; i < HEIGHT - 5; i++) {
    w.setEntity(new Wall (WIDTH/2, i));
  }
  refresh();
}

Level4::Level4 () : Level (WIDTH/2,HEIGHT/2) {}
void Level4::print () {
  for (int i = 0; i < WIDTH; i++) {
    w.setEntity(new Wall (i,0));
    w.setEntity(new Wall (i, HEIGHT-1));
  }

  for (int i = 0; i < HEIGHT; i++) {
    w.setEntity(new Wall (0,i));
    w.setEntity(new Wall (WIDTH-1,i));
  }

  for (int i = 10; i < WIDTH - 10; i++) {
    w.setEntity(new Wall (i, HEIGHT/4));
    w.setEntity(new Wall (i, HEIGHT/2 + HEIGHT/4));
  }
}
