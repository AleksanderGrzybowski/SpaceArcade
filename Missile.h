#ifndef MISSILE_H_
#define MISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "TextureFlipper.h"
#include "Drawable.h"
#include "Moving.h"
#include "Direction.h"
class Missile : public Moving {
public:
	Missile();

	void moveIterate(sf::Time& t);
	virtual int getSize() = 0;

	virtual double getSpeed() = 0;
	virtual int getDamage() = 0;
	void draw(sf::RenderWindow& window);
	Direction getDirection() { return Up; }
	virtual ~Missile() {}

protected:
	virtual std::vector<std::string> getSpritesString() = 0;
	void initialize(int shipx, int shipy);

private:
	TextureFlipper tf;
	sf::Clock animationSpeedClock;
};

#endif /* MISSILE_H_ */
