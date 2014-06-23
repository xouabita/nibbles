#include "player.h"

Player::Player (int x, int y, Window & w) {
  dir = 'l';
  gr = 0;

  plyr.push ( Point (x+1,y) ); // Tail
  plyr.push ( Point (x,y) ); // Head

  w.setEntity (new Nibble (x,y));
  w.setEntity (new Nibble (x+1,y));
}

void Player::grow (int g) { gr += g; }

int Player::move (Window &w) {
  int key = getch();
  int ret_value = NOTHING;
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
      return PAUSE;
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

  char entity = w.getEntity(new_head.x, new_head.y);
  if (entity == WALL || entity == NIBBLE) return LOOSE;
  if (entity >= APPLE_1 && entity <= APPLE_9 ) {
    gr += 1;
    ret_value = EAT;
  }

  // Move the player
  Point tail = plyr.front();

  // Delete the tail
  if (gr == 0) {
    plyr.pop();
    w.delEntity(tail.x,tail.y);
  } else gr--;

  // Add the new head
  plyr.push(new_head);
  w.setEntity(new Nibble(new_head.x,new_head.y));
  return ret_value;
}
