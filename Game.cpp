
#include "Game.h"

Game::Game() : window(sf::VideoMode(screenWidth, screenHeight, 32), "Hello world!") {
	window.setFramerateLimit(60);

}

void Game::addMissile() {
	// znajdź pozycję statku
	sf::Vector2f shipPos = ship.getShape().getPosition();
	missiles.push_back(new Missile(shipPos.x, shipPos.y));
}

void Game::addEnemy() {
	// znajdź pozycję statku
	int xpos = rand() % screenWidth;
	int ypos = rand() % screenHeight + 50;
	enemies.push_back(new Enemy(xpos, ypos));
}

void Game::recalc() { // sprawdzanie kolizji
	for (auto m = missiles.begin(); m != missiles.end(); ++m) {
		for (auto e = enemies.begin(); e != enemies.end(); ++e) { // elementy są wskaźnikami
			sf::Vector2f mpos = (*m)->getPosition();
			sf::Vector2f epos = (*e)->getPosition();
			if ( (abs(mpos.x - epos.x) < 50) && (abs(mpos.y - epos.y) < 50) ) {
				missiles.erase(m);
				enemies.erase(e);
				recalc();
				return;
			}
		}
	}
}

void Game::loop() {
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			window.close();
			exit(0);
		}
	}

	sf::Time t = clock.restart();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		ship.move(false, t);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		ship.move(true, t);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (missileLimitClock.getElapsedTime().asMilliseconds() > 100) {
			addMissile();
			missileLimitClock.restart();
		}
	}

	if (rand() % 10 == 0) addEnemy();

	recalc();

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
}
