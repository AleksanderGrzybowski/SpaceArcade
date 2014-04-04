/*
 * MissileFactory.h
 *
 *  Created on: 4 kwi 2014
 *      Author: kelog
 */

#ifndef MISSILEFACTORY_H_
#define MISSILEFACTORY_H_

#include <SFML/Window.hpp>
#include "Missile.h"
#include "NormalMissile.h"
#include "PowerMissile.h"

class MissileFactory {
public:
	static Missile* getRandomMissile(sf::Vector2f shipPos);
};
#endif /* MISSILEFACTORY_H_ */
