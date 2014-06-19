#include "game.h"

Player::Player (int x, int y, Window & w) {
  dir = 'l';

  plyr.push ( Point (x+1,y) ); // Tail
  plyr.push ( Point (x,y) ); // Head

  w.setEntity (new Nibble (x,y));
  w.setEntity (new Nibble (x+1,y));
}

bool Player::move (Window &w) {
  int key = getch();

  // Change the direction
  switch (key) {
    case KEY_LEFT:
      if (dir != 'r') {
        dir = 'l';
      }
      break;
    case KEY_RIGHT:
      if (dir != 'l') {
        dir = 'r';
      }
      break;
    case KEY_DOWN:
      if (dir != 'u') {
        dir = 'd';
      }
      break;
    case KEY_UP:
      if (dir != 'd') {
        dir = 'u';
      }
      break;
    case ' ':
      return false;
    default:
      break;
  }

  // Move the new head
  Point new_head = plyr.back();
  switch (dir) {
    case 'l':
      new_head.x -= 1;
      break;
    case 'r':
      new_head.x += 1;
      break;
    case 'u':
      new_head.y -= 1;
      break;
    case 'd':
      new_head.y += 1;
      break;
  }

  if (w.getEntity(new_head.x, new_head.y) == WALL) return false;

  // Move the player
  Point tail = plyr.front();

  // Delete the tail
  plyr.pop();
  w.delEntity(tail.x,tail.y);

  // Add the new head
  plyr.push(new_head);
  w.setEntity(new Nibble(new_head.x,new_head.y));
  return true;
}

Game::Game(Level * l) {
  l->print(w);
}

void Game::start () {
  Player p (10,10,w);
  while (p.move(w)) {
    usleep(300000);
  }
}
