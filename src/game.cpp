#include "game.h"

Game::Game(Level * l) {
  l->print(w);

  // Pause Menu
  menu_pause.addItem (new Blank ());
  menu_pause.addItem (new Label ("    Pause     "));
  menu_pause.addItem (new Blank ());
  menu_pause.addItem (new Button ("Continue",0));
  menu_pause.addItem (new Button ("Exit", 1));
  menu_pause.addItem (new Blank ());
  delete l;
}

void Game::start () {
  Player p (10,10,w);
  addApple(w);
  while (1) {
    if (!p.move(w)) {
      menu_pause.draw();
      int res = menu_pause.getSelect();
      if (res) { break; }
      else { w.refresh(); }
    }
    usleep(100000);
  }
}
