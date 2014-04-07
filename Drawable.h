#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "SFML/Graphics.hpp"

class Drawable {
public:
	sf::Sprite sprite;

	virtual void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	virtual const sf::Vector2f& getPosition() {
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
	virtual ~Drawable() {}
};

#endif /* DRAWABLE_H_ */
