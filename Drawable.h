#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "SFML/Graphics.hpp"
#include "TextureFlipper.h"

/* Klasa określająca właściwości obiektu 'rysowalnego'
 * i nie tylko, obiekt ten POSIADA SPRITE!
 */
class Drawable {
public:

	Drawable(int xpos, int ypos, std::vector<std::string> spritesString, int size, int animationSpeed);
	Drawable() : animationSpeed(1337), size(1337) {} // Line tego potrzebuje np.

	virtual void draw(sf::RenderWindow& window);

	const sf::Vector2f& getPosition() const {
		return sprite.getPosition();

	}
	void setPosition(double x, double y) {
		sprite.setPosition(x, y);
	}
	virtual void move(double x, double y) {
		sprite.move(x, y);
	}

	int getSize() const { return size; }

	virtual ~Drawable() {}

protected: // każdy obiekt ma swoje własne:
	sf::Sprite sprite;
	TextureFlipper tf;

	sf::Clock animationSpeedClock;
	int animationSpeed;
	int size;

};

#endif /* DRAWABLE_H_ */
