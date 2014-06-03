#ifndef POINTSCOUNTER_H_
#define POINTSCOUNTER_H_

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "config.h"
#include "Drawable.h"
#include "TextObject.h"

/* Prosty licznik punktów, aktualizowany raz
 * na przebieg głównej pętli.
 */
class PointsCounter : public TextObject {
public:
	PointsCounter(std::string fname);

	void add(int n) { pointsCount += n; updateString(); }
	void reset() { pointsCount = 0; updateString(); }

	// str jest później wyświetlany
	void updateString() {
		str = std::string("Punkty: ") + std::to_string(pointsCount) + " (best " + std::to_string(highScore) + ")";
	}

	void writeHighScore();
	void readHighScore();

private:
	int pointsCount;
	int highScore;
	std::string fname;
};

#endif /* POINTSCOUNTER_H_ */
