#include "TextureFlipper.h"

TextureFlipper::TextureFlipper() : next(0) {
	tab.reserve(10); // unikamy realokacji
}

void TextureFlipper::add(sf::Texture t) {
	tab.push_back(t);
}

void TextureFlipper::add(std::vector<std::string> v) {
	sf::Texture t;

	for (std::string& s : v) {
		if (!fileExists(s)) throw FileNotFoundException(s);
		t.loadFromFile(s);
		tab.push_back(t);
	}
}

sf::Texture& TextureFlipper::getFlip() {
	sf::Texture& ret = tab[next];
	next++;
	if (next == tab.size()) next = 0; // stos
	return ret;
}
