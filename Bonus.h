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

class Bonus: public Moving {
public:
	Bonus() {}

	// przesłaniane w potomnych
	virtual int getPoints() const = 0;
	Direction getDirection() const { return Down; }
	int getAnimationSpeed() const { return 100; }
	virtual ~Bonus() {}

protected:
	//virtual std::vector<std::string> getSpritesString() const = 0;
	virtual void initialize(int xpos, int ypos);
};

#endif /* BONUS_H_ */
