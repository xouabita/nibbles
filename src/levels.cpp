#include "levels.h"

Level::Level (int x, int y) : plyr (x,y,w) {

  // Pause Menu
  menu_pause.addItem (new Blank ());
  menu_pause.addItem (new Label ("    Pause     "));
  menu_pause.addItem (new Blank ());
  menu_pause.addItem (new Button ("Continue",0));
  menu_pause.addItem (new Button ("Exit", 1));
  menu_pause.addItem (new Blank ());
}

void Level::start () {
  addApple(w);
  while (1) {
    if (!plyr.move(w)) {
      menu_pause.draw();
      int res = menu_pause.getSelect();
      if (res) { break; }
      else { w.refresh(); }
    }
    usleep(100000);
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
}
