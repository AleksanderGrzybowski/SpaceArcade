#ifndef TEXTUREFLIPPER_H_
#define TEXTUREFLIPPER_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "fileExists.h"
#include "FileNotFoundException.h"

class TextureFlipper {
public:
	TextureFlipper();

	void add(sf::Texture t);
	void add(std::vector<std::string> v);
	sf::Texture& getFlip();

private:
	std::vector<sf::Texture> tab;
	unsigned int next;
};

#endif /* TEXTUREFLIPPER_H_ */
