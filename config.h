#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>

// Opcje ogólne
static const int CONF_screenWidth = 600;
static const int CONF_screenHeight = 600;
static const std::string CONF_windowTitle = "SpaceArcade Alfa";
static const int CONF_frameRateLimit = 60;

// Statek
static const int CONF_shipSize = 48; // bok kwadratu
static const double CONF_shipSpeed = 0.4;
static const double CONF_shipUpLimit = 0.2; // ile do góry można

// Enemy
static const int CONF_enemySize = 64; // używane żeby nie wyświetlać ich poza ekranem
static const double CONF_enemyDownLimit = 0.3;
static const int CONF_enemyGenerationChance = 1;

// Bonus
static const int CONF_bonusGenerationChance = 1;
// Line
static const int CONF_lineHeight = 2;

#endif /* CONFIG_H_ */
