#include "TextureFlipper.h"

TextureFlipper::TextureFlipper() : next(0) {
	tab.reserve(10); // unikamy realokacji
}

void TextureFlipper::add(const sf::Texture& t) {
	tab.push_back(t);
}

void TextureFlipper::add(const std::vector<std::string> v) {
	sf::Texture t;

	for (const std::string& s : v) {
		if (!fileExists(s)) throw FileNotFoundException(s);
		t.loadFromFile(s);
		tab.push_back(t);
	}
}

const sf::Texture& TextureFlipper::getFlip() {
	const sf::Texture& ret = tab[next];
	next++;
	if (next == tab.size()) next = 0; // stos
	return ret;
}
