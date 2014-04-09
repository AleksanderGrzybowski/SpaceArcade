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
#include "Random.h"

class MissileFactory {
public:
	static Missile* getRandomMissile(int shipx, int shipy);
};

#endif /* MISSILEFACTORY_H_ */
