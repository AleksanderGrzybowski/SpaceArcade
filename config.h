#ifndef CONFIG_H_
#define CONFIG_H_

#include <SFML/Graphics.hpp>
#include <string>

static const std::string CONF_windowTitle = "SpaceArcade Alfa";
static const int CONF_frameRateLimit = 60;
static const int CONF_collisionDistance = 20;

static const int CONF_shipSize = 48; // bok kwadratu
static const sf::Color CONF_shipColor = sf::Color::Yellow;
static const double CONF_shipSpeed = 0.2;
static const double CONF_shipUpLimit = 0.4; // ile do góry można

static const int CONF_screenHeight = 480;
static const int CONF_screenWidth = 640;

static const int CONF_enemySize = 20; // średnica
static const double CONF_enemySpeed = 0.2;
static const int CONF_movementRandomFactor = 5;
static const double CONF_enemyDownLimit = 0.2;

#endif /* CONFIG_H_ */
