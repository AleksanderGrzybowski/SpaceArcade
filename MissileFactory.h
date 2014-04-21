#ifndef MISSILEFACTORY_H_
#define MISSILEFACTORY_H_

#include <SFML/Window.hpp>
#include "Missile.h"
#include "NormalMissile.h"
#include "PowerMissile.h"
#include "Random.h"

/* Ta klasa służy wyłącznie do tworzenia losowych pocisków.
 * W całym programie nie zastosowano wzorca Factory,
 * bo nie było to przydatne ani dobre.
 */
class MissileFactory {
public:
	static Missile* getRandomMissile(int shipx, int shipy);
};

#endif /* MISSILEFACTORY_H_ */
