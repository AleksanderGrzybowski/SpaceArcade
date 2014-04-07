#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "SFML/Graphics.hpp"

class Drawable {
public:
	sf::Sprite sprite;

	virtual void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	const sf::Vector2f& getPosition() {
		return sprite.getPosition();
	}

	virtual ~Drawable() {}
};

#endif /* DRAWABLE_H_ */
