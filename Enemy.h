#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"
#include "Direction.h"
#include "TextureFlipper.h"
#include "Drawable.h"
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

	// przesłaniane
//	virtual double getSpeed() const = 0;
//	virtual int getSize() const = 0;
//	virtual int getMaxHealth() { return maxHealth; }
//	virtual double getDamageCoeff() const = 0;
	virtual int getPoints() { return pointsReceived; }

//	Direction getDirection() const { return Down; }
//	int getAnimationSpeed() const { return 100; }
	bool isAlive() const { return health > 0; }
	void damage(int damage);

	virtual ~Enemy() {}

protected:
	//virtual void initialize(int xpos, int ypos);
	Direction dir;
	int pointsReceived;

private:
	int health;
};

#endif /* ENEMY_H_ */
