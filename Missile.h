#ifndef MISSILE_H_
#define MISSILE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "TextureFlipper.h"
#include "Drawable.h"
#include "Moving.h"
#include "Direction.h"

/* Pocisk wystrzeliwany jest przez statek,
 * po zderzeniu z przeciwnikiem zadaje obrażenia i znika,
 * po zniknięciu z ekranu jest usuwany.
 */
class Missile : public Moving {
public:
	Missile(int shipx, int shipy, const std::vector<std::string>& spritesString, int size, int animationSpeed, double speed, int damage);

	virtual int getDamage() const { return damage; }

	virtual ~Missile() {}

protected:
	const int damage;

};

#endif /* MISSILE_H_ */
