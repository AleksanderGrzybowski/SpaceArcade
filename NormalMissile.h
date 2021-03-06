#ifndef NORMALMISSILE_H_
#define NORMALMISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Missile.h"

/* Implementacja Missile, definiuje jej parametry,
 * takie jak siła rażenia, szybkość itd.
 */
class NormalMissile : public Missile {
public:
	NormalMissile(int shipx, int shipy);

	static void restartClock();
	static bool canBeSent();

private:
	static sf::Clock missileLimitClock;
	static const int timeLimit;
};

#endif /* MISSILE_H_ */
