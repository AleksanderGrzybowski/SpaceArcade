#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>

static const std::string CONF_windowTitle = "SpaceArcade Alfa";
static const int CONF_frameRateLimit = 60;
static const int CONF_animationSpeed = 100; // co 100 ms zmiana tekstury

static const int CONF_shipSize = 48; // bok kwadratu
static const double CONF_shipSpeed = 0.2;
static const double CONF_shipUpLimit = 0.3; // ile do góry można

static const int CONF_screenHeight = 480;
static const int CONF_screenWidth = 640;

static const double CONF_enemyDownLimit = 0.2;

static const int CONF_fontSize = 20;

#endif /* CONFIG_H_ */
