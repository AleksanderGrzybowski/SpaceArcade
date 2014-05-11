#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Direction.h"
#include "TextureFlipper.h"
#include "Moving.h"
#include "Direction.h"

/* Klasa bazowa przeciwnika. Porusza się on w dół,
 * przy kontakcie z linią koniec gry, przy kontakcie z pociskiem
 * zadawany damage i zniknięcie pocisku.
 */
class Enemy : public Moving {
public:
	Enemy(int xpos, int ypos, std::vector<std::string> spritesString, int size,
		int animationSpeed, double speed, int health, int pointsReceived);

	int getPoints() const { return pointsReceived; }
	bool isAlive() const { return health > 0; }
	void damage(int damage) { health -= damage; }

	virtual ~Enemy() {}

protected:
	int health;
	int pointsReceived;
};

#endif /* ENEMY_H_ */
