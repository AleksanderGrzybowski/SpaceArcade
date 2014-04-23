#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "SFML/Graphics.hpp"
#include "TextureFlipper.h"
#include "config.h"


/* Klasa określająca właściwości obiektu 'rysowalnego'
 * i nie tylko
 */
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
	virtual int getAnimationSpeed() const = 0;

	virtual ~Drawable() {}

protected: // każdy obiekt ma swoje własne:
	sf::Sprite sprite;
	TextureFlipper tf;
	sf::Clock animationSpeedClock;

	virtual const std::vector<std::string> getSpritesString() const = 0;
};

#endif /* DRAWABLE_H_ */
