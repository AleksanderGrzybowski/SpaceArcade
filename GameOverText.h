#ifndef GAMEOVERTEXT_H_
#define GAMEOVERTEXT_H_

#include <string>
#include <SFML/Graphics.hpp>
#include "TextObject.h"

class GameOverText : public TextObject {
public:

	GameOverText() {
		setPosition(200, 200);
	}

	int getFontSize() { return 40; }
	sf::Color getColor() { return sf::Color::Yellow; }

private:
	std::string getString() { return "Cienias"; }
};

#endif /* GAMEOVERTEXT_H_ */
