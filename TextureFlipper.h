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
 * Uwaga 2 - nie można dopuścić do realokacji pamięci
 * w wektorze - posypią się przypisane już przez
 * SFML referencje (wskaźniki?) w obiektach Drawable
 */
class TextureFlipper {
public:
	TextureFlipper();

	void add(const sf::Texture& t);
	void add(const std::vector<std::string>& v);
	const sf::Texture& getFlip();

private:
	std::vector<sf::Texture> tab;
	unsigned int next; // wskazuje następny element do wyświetlenia
};

#endif /* TEXTUREFLIPPER_H_ */
