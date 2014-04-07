#ifndef TEXTUREFLIPPER_H_
#define TEXTUREFLIPPER_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class TextureFlipper {
public:
	std::vector<sf::Texture> tab;
	unsigned int next;

	TextureFlipper();

	void add(sf::Texture t);
	void add(std::vector<std::string> v);
	sf::Texture& getFlip();
};

#endif /* TEXTUREFLIPPER_H_ */
