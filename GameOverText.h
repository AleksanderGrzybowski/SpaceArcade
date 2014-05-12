#ifndef GAMEOVERTEXT_H_
#define GAMEOVERTEXT_H_

#include <string>
#include <SFML/Graphics.hpp>
#include "TextObject.h"
#include "config.h"

/* Tekst wyświetlany po przeganiu,
 * czyli kontakcie statku z linią.
 */
class GameOverText : public TextObject {
public:

	GameOverText() : TextObject(CONF_screenWidth/2, CONF_screenHeight/2, 40, sf::Color::Yellow, "Try again")
	{ }

};

#endif /* GAMEOVERTEXT_H_ */
