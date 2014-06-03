#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "SFML/Graphics.hpp"
#include "TextureFlipper.h"

/* Klasa określająca właściwości obiektu 'rysowalnego',
 * obiekt ten POSIADA SPRITE!
 */
class Drawable {
public:

	Drawable(int xpos, int ypos, const std::vector<std::string>& spritesString, int size, int animationSpeed);
	Drawable() : animationSpeed(1), size(1337) {} // Kilka klas potrzebuje się zatroszczyć samo o konstrukcję Drawable

	virtual void draw(sf::RenderWindow& window);

	// Delegacje do sprite:

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
	TextureFlipper tf; // do animacji

	sf::Clock animationSpeedClock; // liczy, kiedy można przerzucić na następną klatkę animacji
	const int animationSpeed;
	const int size;
};

#endif /* DRAWABLE_H_ */
