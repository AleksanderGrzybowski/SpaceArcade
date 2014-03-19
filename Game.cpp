#include "Game.h"

Game::Game() : window(sf::VideoMode(CONF_screenWidth, CONF_screenHeight, 32), CONF_windowTitle), pointCount(0) {
	window.setFramerateLimit(CONF_frameRateLimit);

	if (!font.loadFromFile("Fonts/Arial.ttf")) {
		std::cerr << "Nie idzie czcionki załadować" << std::endl;
		throw std::exception();
	}
}

void Game::addMissile() {
	// znajdź pozycję statku, potrzebną do określenia pozycji pocisku
	sf::Vector2f shipPos = ship.getPosition();
	(rand() % 2) ? missiles.push_back(new NormalMissile(shipPos)) : missiles.push_back(new PowerMissile (shipPos));
}

void Game::addEnemy() {
	// znajdź pozycję statku
	int xpos = rand() % CONF_screenWidth;
	int ypos = (rand() % CONF_screenHeight)*CONF_enemyDownLimit; // górna część miejscem na enemy
	(rand() % 2) ? 	enemies.push_back(new NormalEnemy(xpos, ypos)) : enemies.push_back(new HardEnemy(xpos, ypos));
}

bool Game::checkCollision(sf::Vector2f mpos, sf::Vector2f epos, int msize, int esize) { // pociski są kwadratami!!!
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
			if (checkCollision(mpos, epos, (*m)->getSize(), (*e)->getSize())) { // KOLIZJA JUPI
				std::cout << "Kolizja " << rand() << std::endl;
				int missileDamage = (*m)->getDamage();
				delete *m;
				missiles.erase(m);
				(*e)->damage(missileDamage);
				if (!((*e)->isAlive())) {
					delete *e;
					enemies.erase(e);
					pointCount++; // jakaś fajniejsza logika
				}
				goto againB; // czy to ma sens logiczny?
			}
		}
	}
}

sf::Text Game::getText() {
	sf::Text text;
	text.setFont(font);
	text.setString("Punkty: " + std::to_string(pointCount));
	text.setCharacterSize(20);
	text.setColor(sf::Color::White);
	return text;
}
bool Game::loop() {
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			window.close();
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


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { // NormalMissile
		if ((NormalMissile::missileLimitClock).getElapsedTime().asMilliseconds() > NormalMissile::timeLimit) {
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

	// Rysowanie
	window.clear();

	for (auto& m : missiles) {
		m->moveIterate(t);
		window.draw(*m);
	}

	for (auto& e : enemies) {
		e->moveIterate(t);
		window.draw(*e);
	}

	window.draw(ship);

	// Napis

	window.draw(getText());

	window.display();
	return true;
}


Game::~Game() {
	for (auto m = missiles.begin(); m != missiles.end(); ++m) delete *m;
	for (auto e = enemies.begin(); e != enemies.end(); ++e) delete *e;
	window.close();
}
