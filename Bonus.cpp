#include "Bonus.h"

Bonus::Bonus(int xpos, int ypos, std::vector<std::string> spritesString, int size, int animationSpeed, double speed, int pointsReceived) :
	Moving(xpos, ypos, spritesString, size, animationSpeed, speed, Down), pointsReceived(pointsReceived) {
//	tf.add(spritesString);
//	setTexture(tf.getFlip());
//	setPosition(xpos, ypos);
}
