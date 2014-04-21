#ifndef LINE_H_
#define LINE_H_

#include <SFML/Graphics.hpp>
#include "config.h"
#include "Drawable.h"

class Line : public Drawable {
public:
	Line();

	int getSize() const { return 1337; } // nieistotne - a przynajmniej nie powinno być
	int getAnimationSpeed() const { return 100; } // nieistotne, przynajmniej teraz
	virtual std::vector<std::string> getSpritesString() const {
		return {"Sprites/Line.png"};
	}
};

#endif /* LINE_H_ */
