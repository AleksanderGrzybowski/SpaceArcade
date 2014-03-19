#include "NormalMissile.h"

NormalMissile::NormalMissile(const sf::Vector2f& shipPos) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Sprites/NormalMissile.png");
	r.setTexture(*texture);

	double xpos = shipPos.x + CONF_shipSize/2 - (getSize()/2.0);
	double ypos = shipPos.y;
	r.move(xpos, ypos);
//	r.setFillColor(getColor());
}

sf::Clock NormalMissile::missileLimitClock;
const int NormalMissile::timeLimit = 300; // ms
