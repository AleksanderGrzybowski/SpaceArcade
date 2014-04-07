#include "PointsCounter.h"

PointsCounter::PointsCounter() : pointsCount(0) {
	if (!font.loadFromFile("Fonts/Arial.ttf")) { // should never happen
		std::cerr << "Nie idzie czcionki załadować" << std::endl;
		throw std::exception();
	}
}

void PointsCounter::draw(sf::RenderWindow& window) {
	sf::Text text;
	text.setFont(font);
	text.setString("Punkty: " + std::to_string(pointsCount));
	text.setCharacterSize(CONF_fontSize);
	text.setColor(sf::Color::White);

	window.draw(text);
}
