#include "Game.h"

Game::Game() : window(sf::VideoMode(CONF_screenWidth, CONF_screenHeight, 32), "SpaceArcade") {
	window.setFramerateLimit(60);
}

void Game::addMissile() {
	// znajdź pozycję statku
	sf::Vector2f shipPos = ship.getPosition();
	if (rand() % 2)
		missiles.push_back(new NormalMissile(shipPos.x + CONF_shipSize/2 - (CONF_missileSize/2), shipPos.y));
	else
		missiles.push_back(new PowerMissile (shipPos.x + CONF_shipSize/2 - (CONF_missileSize/2), shipPos.y));
}

void Game::addEnemy() {
	// znajdź pozycję statku
	int xpos = rand() % CONF_screenWidth;
	int ypos = (rand() % CONF_screenHeight)/2; // górna połowa miejscem na enemy
	if (rand() % 2)
		enemies.push_back(new NormalEnemy(xpos, ypos));
	else
		enemies.push_back(new HardEnemy(xpos, ypos));
}

void Game::recalc() {
	// pociski poza ekranem
againA:
	for (auto m = missiles.begin(); m != missiles.end(); ++m) {
		sf::Vector2f mpos = (*m)->getPosition();
		if (mpos.y <= 0) {
			//std::cout << "Usuwam pocisk " << mpos.x << std::endl;
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
			if ( (abs(mpos.x - epos.x) < 50) && (abs(mpos.y - epos.y) < 50) ) { // KOLIZJA

//				missiles.erase(m); // proste, zmieniam na to uwzgl. damage
//				enemies.erase(e);
				int missileDamage = (*m)->getDamage();
				missiles.erase(m);
				(*e)->damage(missileDamage);
				if (!((*e)->isAlive())) enemies.erase(e);
				goto againB;
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
			missiles.push_back(new NormalMissile(shipPos.x + CONF_shipSize/2 - (CONF_missileSize/2), shipPos.y));
			NormalMissile::missileLimitClock.restart();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { // PowerMissile
		if ((PowerMissile::missileLimitClock).getElapsedTime().asMilliseconds() > 100) {
			sf::Vector2f shipPos = ship.getPosition();
			missiles.push_back(new PowerMissile(shipPos.x + CONF_shipSize/2 - (CONF_missileSize/2), shipPos.y));
			PowerMissile::missileLimitClock.restart();
		}
	}


	if (rand() % 50 == 0) addEnemy();

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
