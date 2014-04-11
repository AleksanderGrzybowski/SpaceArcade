#include "Bonus.h"

void Bonus::initialize(int xpos, int ypos) {
	tf.add(getSpritesString());
	setTexture(tf.getFlip());
	setPosition(xpos, ypos);
}
