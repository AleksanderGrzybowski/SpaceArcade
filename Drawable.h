#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "SFML/Graphics.hpp"
#include "TextureFlipper.h"
#include "config.h"

/* Klasa określająca właściwości obiektu 'rysowalnego'
 * i nie tylko, obiekt ten POSIADA SPRITE!
 */
class Drawable {
public:

	// może pozycja też tu? albo nie?
	Drawable(int xpos, int ypos, std::vector<std::string> spritesString, int size, int animationSpeed) : animationSpeed(animationSpeed), size(size) {
		tf.add(spritesString);
		sprite.setTexture(tf.getFlip());
		setPosition(xpos, ypos);
	}

	// ?? zmienić
	Drawable() : animationSpeed(1337), size(1337) {} // Line tego potrzebuje np.

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

	int getSize() {
		return size;
	}

	// przesłaniane
	//virtual int getAnimationSpeed() const = 0;

	virtual ~Drawable() {}

protected: // każdy obiekt ma swoje własne:
	sf::Sprite sprite;
	TextureFlipper tf;
	sf::Clock animationSpeedClock;
	int animationSpeed;
	int size;

	//virtual const std::vector<std::string> getSpritesString() const = 0;
};

#endif /* DRAWABLE_H_ */
