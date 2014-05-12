#ifndef BONUS_H_
#define BONUS_H_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Moving.h"
#include "TextureFlipper.h"
#include "config.h"
#include "Drawable.h"
#include "Direction.h"

/* Spadający w dół obiekt bonusowy, który znika po kontakcie ze statkiem,
 * znika także, jeśli wyjdzie poza ekran.
 * Po kontakcie tym gracz otrzymuje punkty.
 * Kontakt z przeciwnikiem nie ma znaczenia, nie jest sprawdzany.
 * Bonus po kontakcie jest usuwany z gry w pętli głównej.
 */
class Bonus: public Moving {
public:
	Bonus(int xpos, int ypos, const std::vector<std::string>& spritesString, int size, int animationSpeed, double speed, int pointsReceived);

	// Ile gracz uzyskuje punktów po kontakcie z bonusem
	virtual int getPoints() const { return pointsReceived; }

	virtual ~Bonus() {}

protected:
	const int pointsReceived; // otrzymywane punkty
};

#endif /* BONUS_H_ */
