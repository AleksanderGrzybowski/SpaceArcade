#include "Drawable.h"


void Drawable::draw(sf::RenderWindow& window) {

	if ((animationSpeedClock).getElapsedTime().asMilliseconds() > CONF_animationSpeed) {
		sprite.setTexture(tf.getFlip());
		animationSpeedClock.restart();
	}
	window.draw(sprite);
}


