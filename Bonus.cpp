#include "Bonus.h"

Bonus::Bonus(int xpos, int ypos, std::vector<std::string> spritesString) : Moving(spritesString) {
//	tf.add(spritesString);
//	setTexture(tf.getFlip());
	setPosition(xpos, ypos);
}
