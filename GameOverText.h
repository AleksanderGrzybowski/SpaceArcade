#ifndef GAMEOVERTEXT_H_
#define GAMEOVERTEXT_H_

#include <string>
#include <SFML/Graphics.hpp>
#include "TextObject.h"
#include "config.h"

class GameOverText : public TextObject {
public:

	GameOverText() : TextObject(CONF_screenWidth/2, CONF_screenHeight/2, 40, sf::Color::Yellow) {
		str = "Cienias";
	}

//	int getFontSize() { return 40; }
//	sf::Color getColor() { return sf::Color::Yellow; }

//private:
//	std::string getString() { return "Cienias"; }
};

#endif /* GAMEOVERTEXT_H_ */
