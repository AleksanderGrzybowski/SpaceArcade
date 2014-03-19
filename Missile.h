#ifndef MISSILE_H_
#define MISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"

class Missile {
public:
	sf::CircleShape r;


	Missile(double xpos, double ypos);

	void moveIterate(const sf::Time& t);
	sf::Shape& getShape() { return r; }
	sf::Vector2f getPosition() { return r.getPosition(); }
	virtual double getSpeed() { return CONF_missileSpeed; }

//	virtual Missile* newMissile(double xpos, double ypos) { // wywalić
//		return new Missile(xpos, ypos);
//	}
	virtual int getDamage() = 0;

	virtual ~Missile() {}
};

#endif /* MISSILE_H_ */
