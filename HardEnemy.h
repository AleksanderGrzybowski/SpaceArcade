#ifndef HARDENEMY_H_
#define HARDENEMY_H_

#include <SFML/Graphics.hpp>
#include "Enemy.h"

class HardEnemy: public Enemy {
public:
	HardEnemy(double xpos, double ypos);
};

#endif /* HARDENEMY_H_ */
