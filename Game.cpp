#include "Game.h"

Game::Game() : window(sf::VideoMode(CONF_screenWidth, CONF_screenHeight, 32), CONF_windowTitle) {
	window.setFramerateLimit(CONF_frameRateLimit);
}

void Game::addMissile() {
	// znajdź pozycję statku
	sf::Vector2f shipPos = ship.getPosition();
	(rand() % 2) ? missiles.push_back(new NormalMissile(shipPos)) : missiles.push_back(new PowerMissile (shipPos));
}

void Game::addEnemy() {
	// znajdź pozycję statku
	int xpos = rand() % CONF_screenWidth;
	int ypos = (rand() % CONF_screenHeight)*CONF_enemyDownLimit; // górna część miejscem na enemy
	(rand() % 2) ? 	enemies.push_back(new NormalEnemy(xpos, ypos)) : enemies.push_back(new HardEnemy(xpos, ypos));
}

void Game::recalc() {
	// pociski poza ekranem
againA:
	for (auto m = missiles.begin(); m != missiles.end(); ++m) {
		sf::Vector2f mpos = (*m)->getPosition();
		if (mpos.y <= 0) {
			missiles.erase(m);
			goto againA;
		}
	}

againB:
	// sprawdzanie kolizji
	for (auto m = missiles.begin(); m != missiles.end(); ++m) {
		for (auto e = enemies.begin(); e != enemies.end(); ++e) { // elementy są wskaźnikami
			sf::Vector2f mpos = (*m)->getPosition();
			sf::Vector2f epos = (*e)->getPosition();
			if ( (abs(mpos.x - epos.x) < CONF_collisionDistance) && (abs(mpos.y - epos.y) < CONF_collisionDistance) ) { // KOLIZJA
				int missileDamage = (*m)->getDamage();
				missiles.erase(m);
				(*e)->damage(missileDamage);
				if (!((*e)->isAlive())) enemies.erase(e);
				goto againB; // czy to ma sens logiczny?
			}
		}
	}
}

bool Game::loop() {
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			window.close();
			return false;
		}
	}

	// Restart głównego zegara
	sf::Time t = clock.restart();

	// Poruszanie statkiem
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		ship.move(Left, t);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		ship.move(Right, t);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		ship.move(Up, t);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		ship.move(Down, t);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { // NormalMissile
		if ((NormalMissile::missileLimitClock).getElapsedTime().asMilliseconds() > 100) {
			sf::Vector2f shipPos = ship.getPosition();
			missiles.push_back(new NormalMissile(shipPos));
			NormalMissile::missileLimitClock.restart();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { // PowerMissile
		if ((PowerMissile::missileLimitClock).getElapsedTime().asMilliseconds() > PowerMissile::timeLimit) {
			sf::Vector2f shipPos = ship.getPosition();
			missiles.push_back(new PowerMissile(shipPos));
			PowerMissile::missileLimitClock.restart();
		}
	}


	if (rand() % 50 == 0) addEnemy();

	// Achtung
	recalc();
	// Już spoko


	// Rysowanie
	window.clear();

	for (auto& m : missiles) {
		m->moveIterate(t);
		window.draw(m->getShape());
	}

	for (auto& e : enemies) {
		e->moveIterate(t);
		window.draw(e->getShape());
	}

	window.draw(ship.getShape());
	window.display();

	return true;
}
