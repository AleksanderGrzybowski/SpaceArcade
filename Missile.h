#ifndef MISSILE_H_
#define MISSILE_H_
#include <SFML/Graphics.hpp>

class Missile { // z niej można by wywodzić pozostałe
public:
	sf::RectangleShape r;

	Missile(double xpos, double ypos);

	void moveIterate(sf::Time& t);

	sf::Shape& getShape() { return r; }
	sf::Vector2f getPosition() { return r.getPosition(); }
};

#endif /* MISSILE_H_ */
