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

private:
	std::string getString() { return "Cienias"; }
};

#endif /* GAMEOVERTEXT_H_ */
