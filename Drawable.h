#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "SFML/Graphics.hpp"
#include "TextureFlipper.h"
#include "config.h"
class Drawable {
public:

	virtual void draw(sf::RenderWindow& window);

	virtual const sf::Vector2f& getPosition() const {
		return sprite.getPosition();
	}
	virtual void setPosition(double x, double y) {
		sprite.setPosition(x, y);
	}
	virtual void move(double x, double y) {
		sprite.move(x, y);
	}
	virtual void setTexture(sf::Texture& t) {
		sprite.setTexture(t);
	}
	virtual int getSize() const = 0;

	virtual ~Drawable() {}

protected:
	sf::Sprite sprite;
	TextureFlipper tf;
	sf::Clock animationSpeedClock;
};

#endif /* DRAWABLE_H_ */
