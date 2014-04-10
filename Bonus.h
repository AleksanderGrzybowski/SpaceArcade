#ifndef BONUS_H_
#define BONUS_H_

#include "Drawable.h"
#include "Moving.h"
#include "TextureFlipper.h"
#include <SFML/Graphics.hpp>
#include "config.h"
#include <vector>
#include <string>
#include "Drawable.h"
#include "Direction.h"

class Bonus: public Moving {
public:
	Bonus() {}
	virtual void moveIterate(sf::Time& t);

	// przesłaniane w potomnych
	virtual double getSpeed() = 0;
	virtual int getSize() = 0;
	virtual int getPoints() = 0;
	Direction getDirection() { return Down; }
	virtual ~Bonus() {}

protected:
	virtual std::vector<std::string> getSpritesString() = 0;
	virtual void initialize(int xpos, int ypos);
private:
	TextureFlipper tf;
};

#endif /* BONUS_H_ */
