#ifndef NORMALMISSILE_H_
#define NORMALMISSILE_H_
#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

class NormalMissile : public Missile { // z niej można by wywodzić pozostałe
public:


	NormalMissile(double xpos, double ypos);

};

#endif /* MISSILE_H_ */
