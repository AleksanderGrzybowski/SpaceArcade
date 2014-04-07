#ifndef MISSILE_H_
#define MISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "TextureFlipper.h"
class Missile {
public:
	sf::Sprite shape;
	TextureFlipper tf;
	sf::Clock animationSpeedClock;

	Missile();

	void moveIterate(const sf::Time& t);
	sf::Vector2f getPosition() { return shape.getPosition(); }
	virtual int getSize() = 0;

	void initialize(int shipx, int shipy);
	virtual std::vector<std::string> getSpritesString() = 0;
	virtual double getSpeed() = 0;
	virtual int getDamage() = 0;
	void draw(sf::RenderWindow& window);


	virtual ~Missile() {}
};

#endif /* MISSILE_H_ */
