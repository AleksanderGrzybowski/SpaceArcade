#include "Game.h"

Game::Game() : window(sf::VideoMode(CONF_screenWidth, CONF_screenHeight, 32), CONF_windowTitle) {
	window.setFramerateLimit(CONF_frameRateLimit);
}

void Game::reset() {
	pc.reset();
	for (unsigned int i = 0; i < missiles.size(); ++i) delete missiles[i];
	for (unsigned int i = 0; i < enemies.size(); ++i) delete enemies[i];
	missiles.clear();
	enemies.clear();
	window.clear();
}

void Game::addMissile() {
	// znajdź pozycję statku, potrzebną do określenia pozycji pocisku
	sf::Vector2f shipPos = ship.getPosition();
	missiles.push_back(MissileFactory::getRandomMissile(shipPos.x, shipPos.y));
}

void Game::addEnemy() {
	Enemy* e = EnemyFactory::getRandomEnemy(0, 0); // dowolne
	int xpos = rand() % CONF_screenWidth - e->getSize(); // nie można inaczej
	int ypos = (rand() % CONF_screenHeight)*CONF_enemyDownLimit; // górna część miejscem na enemy
	e->setPosition(xpos, ypos);
	enemies.push_back(e);
}

bool Game::isCollision(sf::Vector2f mpos, sf::Vector2f epos, int msize, int esize) { // pociski są kwadratami!!!
	sf::Vector2f msizes(msize, msize);
	sf::Vector2f esizes(esize, esize);

	sf::Rect<float> mrect(mpos, msizes);
	sf::Rect<float> erect(epos, esizes);

	return mrect.intersects(erect);
}

void Game::recalc() {
	// pociski poza ekranem
againA:
	for (auto m = missiles.begin(); m != missiles.end(); ++m) {
		sf::Vector2f mpos = (*m)->getPosition();
		if (mpos.y <= 0) {
			delete *m;
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
			if (isCollision(mpos, epos, (*m)->getSize(), (*e)->getSize())) { // KOLIZJA JUPI
				int missileDamage = (*m)->getDamage();
				delete *m;
				missiles.erase(m);
				(*e)->damage(missileDamage);
				if (!((*e)->isAlive())) {
					pc.add((*e)->getPoints());
					delete *e;
					enemies.erase(e);

				}
				goto againB; // czy to ma sens logiczny? chyba działa
			}
		}
	}

	// Czy przypadkiem gracz nie wtopił
	for (auto e = enemies.begin(); e != enemies.end(); ++e) {
		sf::Vector2f epos = (*e)->getPosition();
		if (epos.y > (-CONF_shipSize + CONF_screenHeight*(1-CONF_enemyDownLimit))) {
			//throw std::exception();
			std::cout << "Wtapiasz: pozycja przeciwnika " << epos.x << " " << epos.y << std::endl;
		}
	}
}



bool Game::loop() {
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			return false;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		window.close();
		return false;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		reset();
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { // NormalMissile
		if (NormalMissile::canBeSent()) {
			sf::Vector2f shipPos = ship.getPosition();
			missiles.push_back(new NormalMissile(shipPos.x, shipPos.y));
			NormalMissile::missileLimitClock.restart();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { // PowerMissile
		if (PowerMissile::canBeSent()) {
			sf::Vector2f shipPos = ship.getPosition();
			missiles.push_back(new PowerMissile(shipPos.x, shipPos.y));
			PowerMissile::missileLimitClock.restart();
		}
	}

	if (rand() % CONF_enemyGenerationFactor == 0) addEnemy();

	// Achtung
	recalc();

	// Rysowanie
	window.clear();

	for (auto& m : missiles) {
		m->moveIterate(t);
		m->draw(window);
	}

	for (auto& e : enemies) {
		//std::cout << "Mamy łącznie " << enemies.size() << " przeciwnikow" << std::endl;
		e->moveIterate(t);
		e->draw(window);
	}

	ship.draw(window);
	line.draw(window);
	// Napis
	pc.draw(window);

	window.display();
	return true;
}

Game::~Game() {
	for (auto m = missiles.begin(); m != missiles.end(); ++m) delete *m;
	for (auto e = enemies.begin(); e != enemies.end(); ++e) delete *e;
	window.close();
}
