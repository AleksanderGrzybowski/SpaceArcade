#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>

// Opcje ogólne
static const int CONF_screenWidth = 600;
static const int CONF_screenHeight = 600;
static const std::string CONF_windowTitle = "SpaceArcade Alfa";
static const int CONF_fontSize = 20;
static const int CONF_frameRateLimit = 60;
static const int CONF_animationSpeed = 100; // co 100 ms zmiana tekstury

// Statek
static const int CONF_shipSize = 48; // bok kwadratu
static const double CONF_shipSpeed = 0.4;
static const double CONF_shipUpLimit = 0.5; // ile do góry można

// Enemy
static const int CONF_enemySize = 64; // używane żeby nie wyświetlać ich poza ekranem
static const double CONF_enemyDownLimit = 0.3;
static const double CONF_enemySpeed = 0.1;
static const int CONF_enemyGenerationFactor = 20;
static const double CONF_globalEnemySpeedFactor = 300.0;


// Line
static const int CONF_lineHeight = 5;
#endif /* CONFIG_H_ */
