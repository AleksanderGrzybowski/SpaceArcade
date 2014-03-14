
#include "Game.h"

Game::Game() : window(sf::VideoMode(screenWidth, screenHeight, 32), "Hello world!") {
	window.setFramerateLimit(60);

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

	window.clear();
	window.draw(ship.getShape());
	window.display();
}
