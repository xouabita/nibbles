#include "levels.h"

void Level1::print(Window &w) {
  for (int i = 0; i < WIDTH; i++) {
    w.setEntity(new Wall (i,0));
    w.setEntity(new Wall (i, HEIGHT-1));
  }

  for (int i = 0; i < HEIGHT; i++) {
    w.setEntity(new Wall (0,i));
    w.setEntity(new Wall (WIDTH-1,i));
  }
}
