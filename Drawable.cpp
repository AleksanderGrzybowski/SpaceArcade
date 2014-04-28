#include "Drawable.h"

/* Ta metoda jest wykorzystywana wszędzie tam, gdzie wyświetlany jest sprite,
 * czyli nie gdzie tekst czy inne takie! Nie ma opcji tworzenia obiektu bez animacji, bo
 * wymagałoby to wyświetlania go 'raz' i trzymania informacji, czy został
 * on wyświetlony, a tak jest prościej i niespecjalnie wolniej.
 */
void Drawable::draw(sf::RenderWindow& window) {
	if ((animationSpeedClock).getElapsedTime().asMilliseconds() > getAnimationSpeed()) {
		sprite.setTexture(tf.getFlip());
		animationSpeedClock.restart();
	}
	window.draw(sprite);
}
