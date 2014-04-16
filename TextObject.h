#ifndef TEXTOBJECT_H_
#define TEXTOBJECT_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"
#include "Drawable.h"
#include "FileNotFoundException.h"
#include "fileExists.h"
#include <string>

class TextObject {
public:

	TextObject();

	void draw(sf::RenderWindow& window);
	void setPosition(int x, int y) { xpos = x; ypos = y; }

	virtual std::string getString() = 0;
	virtual int getFontSize() = 0;
	virtual sf::Color getColor() = 0;
	virtual ~TextObject() {}

protected:
	sf::Font font;

private:
	int xpos, ypos;

};

#endif /* TEXTOBJECT_H_ */
