#ifndef TEXTUREFLIPPER_H_
#define TEXTUREFLIPPER_H_

#include <vector>
#include <SFML/Graphics.hpp>

class TextureFlipper {
public:
	std::vector<sf::Texture> tab;
	unsigned int next;

	TextureFlipper();
	void add(sf::Texture t);
	sf::Texture& getFlip();

};

#endif /* TEXTUREFLIPPER_H_ */
