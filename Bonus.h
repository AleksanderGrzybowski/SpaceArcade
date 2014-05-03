#ifndef BONUS_H_
#define BONUS_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Moving.h"
#include "TextureFlipper.h"
#include "config.h"
#include "Drawable.h"
#include "Direction.h"

/* Spadający obiekt, który znika po kontakcie ze statkiem.
 * Kontakt z przeciwnikiem nie ma znaczenia.
 */
class Bonus: public Moving {
public:
	Bonus(int xpos, int ypos, std::vector<std::string> spritesString, int size, int animationSpeed, double speed, int pointsReceived);

	// przesłaniane w potomnych
	virtual int getPoints() { return pointsReceived; }

//	Direction getDirection() const { return Down; }
//	int getAnimationSpeed() const { return 100; }

	virtual ~Bonus() {}

protected:
	int pointsReceived;


	//virtual void initialize(int xpos, int ypos);
};

#endif /* BONUS_H_ */
