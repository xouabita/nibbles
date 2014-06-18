#include "entities.h"

Entity::Entity (int t, int x, int y): type (t), x (x), y (y) {}
int Entity::getX () { return x; }
int Entity::getY () { return y; }
