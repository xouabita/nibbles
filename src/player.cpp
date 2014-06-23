#include "player.h"

Player::Player (int x, int y, Window & w) {
  dir = 'l';
  gr = 0;

  plyr.push ( Point (x+1,y) ); // Tail
  plyr.push ( Point (x,y) ); // Head

  w.setEntity (new Nibble (x,y));
  w.setEntity (new Nibble (x+1,y));
  refresh();
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
  if (entity == WALL || entity == NIBBLE || entity == NIBBLE_2) return LOOSE;
  if (entity >= APPLE_1 && entity <= APPLE_7 || entity == APPLE) {
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

AI::AI (int x, int y, Window & w) {
  dir = 'r';
  gr  = 0;

  ai.push ( Point (x-1,y) );
  ai.push ( Point (x,y) );

  w.setEntity (new Nibble2 (x,y));
  w.setEntity (new Nibble2 (x-1,y));
  refresh();
}

void AI::grow (int g) { gr += g; }

int AI::verifyDir (char d,Window w) {
  Point hd = ai.back();
  int c;
  switch (d) {
    case 'u':
      c = w.getEntity(hd.x,hd.y-1);
      break;
    case 'd':
      c = w.getEntity(hd.x,hd.y+1);
      break;
    case 'l':
      c = w.getEntity(hd.x-1,hd.y);
      break;
    case 'r':
      c = w.getEntity(hd.x+1,hd.y);
      break;
  }
  return (c == EMPTY || c == APPLE);
}

int AI::move(Window &w) {

  // Find the best solution
  if (!verifyDir(dir,w)) {
    if (dir != 'd' && verifyDir ('u',w)) {
      dir = 'u';
    }
    else if (dir != 'u' && verifyDir ('d',w)) {
      dir = 'd';
    }
    else if (dir != 'l' && verifyDir ('r',w)) {
      dir = 'r';
    }
    else if (dir != 'r' && verifyDir ('l',w)) {
      dir = 'l';
    }
  }

  // Move the new head
  int ret_value;
  Point new_head = ai.back();
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
  if (entity == WALL || entity == NIBBLE || entity == NIBBLE_2) return LOOSE;
  if (entity >= APPLE_1 && entity <= APPLE_7 || entity == APPLE) {
    gr += 1;
    ret_value = EAT;
  }

  // Move the AI
  Point tail = ai.front();

  // Delete the tail
  if (gr == 0) {
    ai.pop();
    w.delEntity(tail.x,tail.y);
  } else gr--;

  // Add the new head
  ai.push(new_head);
  w.setEntity(new Nibble2(new_head.x,new_head.y));
  return ret_value;
}
