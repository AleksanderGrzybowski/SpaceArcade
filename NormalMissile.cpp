#include "NormalMissile.h"

NormalMissile::NormalMissile(double xpos, double ypos) : Missile(xpos, ypos) {}

//void NormalMissile::moveIterate(const sf::Time& t) {
//	sf::Vector2f actPos = r.getPosition();
//	// tylko w górę
//	actPos.y -= CONF_missileSpeed * t.asMilliseconds();
//	r.setPosition(actPos);
//}
//
