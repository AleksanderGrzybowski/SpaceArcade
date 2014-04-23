#include "Drawable.h"

/* Ta metoda jest wykorzystywana wszędzie tam, gdzie wyświetlany jest sprite,
 * czyli nie gdzie tekst np. Nie ma opcji tworzenia obiektu bez animacji, bo
 * wymagałoby to wyświetlania go 'raz' i trzymania informacji, czy został
 * on wyświetlony, a tak jest prościej i niespecjalnie wolniej (hehe).
 */
void Drawable::draw(sf::RenderWindow& window) {

	int animSpeed = getAnimationSpeed();

	if ((animationSpeedClock).getElapsedTime().asMilliseconds() > animSpeed) {
		sprite.setTexture(tf.getFlip());
		animationSpeedClock.restart();
	}
	window.draw(sprite);
}
