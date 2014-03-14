#ifndef SHIP_H_
#define SHIP_H_

using namespace std; // niezalecane, trudno
#include "config.h"

class Ship {
public:
	sf::CircleShape shape; // potem sprite
public:
	Ship();
	void move(bool b, sf::Time& t); // przez zegar, zmienić na enum
	void setPosition(double x, double y);
	sf::Shape& getShape() { return shape; }

};

#endif /* SHIP_H_ */
