#ifndef LINE_H_
#define LINE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Drawable.h"

class Line : public Drawable {
public:
	Line();
	int getSize() const { return 1337; }


private:
//	sf::Texture texture; // potrzebne, bo zarządzane po swojemu

};

#endif /* LINE_H_ */
