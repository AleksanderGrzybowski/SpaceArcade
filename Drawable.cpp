#include "Drawable.h"


void Drawable::draw(sf::RenderWindow& window) {

	int animSpeed = getAnimationSpeed();

	if ((animationSpeedClock).getElapsedTime().asMilliseconds() > animSpeed) {
		sprite.setTexture(tf.getFlip());
		animationSpeedClock.restart();
	}
	window.draw(sprite);
}


