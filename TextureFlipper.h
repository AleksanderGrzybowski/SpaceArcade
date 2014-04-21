#ifndef TEXTUREFLIPPER_H_
#define TEXTUREFLIPPER_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "fileExists.h"
#include "FileNotFoundException.h"

/* Klasa obsługująca proste animacje wieloklatkowe,
 * proste przełączanie pomiędzy teksturami.
 * Uwaga - nawet, jeśli element ma 1 teksturę to jest
 * wykonywana 'animacja' (bez side effect ofc)
 */
class TextureFlipper {
public:
	TextureFlipper();

	void add(sf::Texture t); // pojedyncza już wczytana
	void add(std::vector<std::string> v); // wiele, ale może być też 1 element
	sf::Texture& getFlip();

private:
	std::vector<sf::Texture> tab;
	unsigned int next;
};

#endif /* TEXTUREFLIPPER_H_ */
