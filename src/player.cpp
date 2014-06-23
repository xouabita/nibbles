#include "player.h"

void addApple(Window &w) {
  srand(time(NULL));
  int x = rand() % WIDTH;
  int y = rand() % HEIGHT;
  if (w.getEntity(x,y) == EMPTY) {
    w.setEntity (new Apple (x,y));
  } else { addApple(w); }
}

Player::Player (int x, int y, Window & w) {
  dir = 'l';
  grow = 0;

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

  if (w.getEntity(new_head.x, new_head.y) == WALL || w.getEntity(new_head.x,new_head.y) == NIBBLE) return false;
  if (w.getEntity(new_head.x, new_head.y) == APPLE) {
    grow += 5;
    addApple(w);
  }

  // Move the player
  Point tail = plyr.front();

  // Delete the tail
  if (grow == 0) {
    plyr.pop();
    w.delEntity(tail.x,tail.y);
  } else grow--;

  // Add the new head
  plyr.push(new_head);
  w.setEntity(new Nibble(new_head.x,new_head.y));
  return true;
}
