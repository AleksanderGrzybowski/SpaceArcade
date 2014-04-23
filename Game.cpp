#include "Game.h"

Game::Game() : window(sf::VideoMode(CONF_screenWidth, CONF_screenHeight, 32), CONF_windowTitle) {
	window.setFramerateLimit(CONF_frameRateLimit);
}

void Game::reset() {
	pc.reset();
	for (unsigned int i = 0; i < missiles.size(); ++i) delete missiles[i];
	for (unsigned int i = 0; i < enemies.size(); ++i) delete enemies[i];
	for (unsigned int i = 0; i < bonuses.size(); ++i) delete bonuses[i];
	missiles.clear();
	enemies.clear();
	bonuses.clear();
	window.clear();
}

void Game::addMissile() {
	// znajdź pozycję statku, potrzebną do określenia pozycji pocisku
	sf::Vector2f shipPos = ship.getPosition();
	missiles.push_back(MissileFactory::getRandomMissile(shipPos.x, shipPos.y));
}

void Game::addEnemy() {
	Enemy* e = EnemyFactory::getRandomEnemy(0, 0); // dowolne
	int xpos = Random::getInt(0, CONF_screenWidth - e->getSize());
	int ypos = Random::getInt(0, CONF_screenHeight)*CONF_enemyDownLimit; // górna część miejscem na enemy
	e->setPosition(xpos, ypos);
	enemies.push_back(e);
}

void Game::addBonus() {
	Bonus* b = new SimpleBonus(0, 0); // dowolne
	int xpos = Random::getInt(0, CONF_screenWidth - b->getSize());
	int ypos = Random::getInt(0, CONF_screenHeight)*CONF_enemyDownLimit; // górna część miejscem na bonusy też
	b->setPosition(xpos, ypos);
	bonuses.push_back(b);
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
againMissilesOff:
	for (auto m = missiles.begin(); m != missiles.end(); ++m) {
		sf::Vector2f mpos = (*m)->getPosition();
		if (mpos.y <= 0) {
			delete *m;
			missiles.erase(m);
			goto againMissilesOff;
		}
	}
	// bonusy poza ekranem
againBonusesOff:
	for (auto b = bonuses.begin(); b != bonuses.end(); ++b) {
		sf::Vector2f pos = (*b)->getPosition();
		if (pos.y >= CONF_screenHeight) {
			delete *b;
			bonuses.erase(b);
			goto againBonusesOff;
		}
	}

againMissilesCrash:
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
				goto againMissilesCrash; // czy to ma sens logiczny? chyba działa
			}
		}
	}

// Pochłanianie bonusów
againBonusCatch:
	// sprawdzanie kolizji
	sf::Vector2f shipPos = ship.getPosition();
	for (auto b = bonuses.begin(); b != bonuses.end(); ++b) { // elementy są wskaźnikami
		sf::Vector2f pos = (*b)->getPosition();
		if (isCollision(pos, shipPos, (*b)->getSize(), CONF_shipSize)) { // KOLIZJA JUPI
			pc.add((*b)->getPoints());
			delete *b;
			bonuses.erase(b);
			goto againBonusCatch; // czy to ma sens logiczny? chyba działa
		}
	}



	// Czy przypadkiem gracz nie wtopił
	for (auto e = enemies.begin(); e != enemies.end(); ++e) {
		sf::Vector2f epos = (*e)->getPosition();
		if (epos.y > (CONF_screenHeight*(1-CONF_shipUpLimit) - CONF_enemySize)) {
			throw GameOverException();
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

	if (Random::tryChance(CONF_enemyGenerationChance)) addEnemy();
	if (Random::tryChance(CONF_bonusGenerationChance)) addBonus();

	// Achtung!!! Ważne rzeczy się dzieją właśnie tu
	try {
		recalc();
	} catch (GameOverException&) {
		gameOver();
		reset();
	}

	// Rysowanie
	window.clear();

	for (auto& m : missiles) {
		m->moveIterate(t);
		m->draw(window);
	}

	for (auto& e : enemies) {
		e->moveIterate(t);
		e->draw(window);
	}

	for (auto& b : bonuses) {
		b->moveIterate(t);
		b->draw(window);
	}

	ship.draw(window);
	line.draw(window);
	// Napis
	pc.draw(window);

	window.display();
	return true;
}

void Game::gameOver() {
	GameOverText gt;
	gt.draw(window);
	window.display();
	//sleep(1);

	sf::Clock cl;
	cl.restart();
	while (cl.getElapsedTime().asMilliseconds() < 1000);
}


Game::~Game() {
//	for (auto m = missiles.begin(); m != missiles.end(); ++m) delete *m;
//	for (auto e = enemies.begin(); e != enemies.end(); ++e) delete *e;
	reset();
	window.close();
}
