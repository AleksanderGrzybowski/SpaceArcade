#ifndef CONFIG_H_
#define CONFIG_H_

#include <SFML/Graphics.hpp>

static const int CONF_shipSize = 20; // średnica
static const sf::Color CONF_shipColor = sf::Color::Yellow;
static const double CONF_shipSpeed = 0.2;
static const double CONF_shipUpLimit = 0.1; // ile do góry można

static const int CONF_screenHeight = 480;
static const int CONF_screenWidth = 640;

static const double CONF_missileSpeed = 0.5;
static const int CONF_missileSize = 20; // średnica

static const int CONF_enemySize = 20; // średnica
static const double CONF_enemySpeed = 0.2;
static const int CONF_movementRandomFactor = 5;

#endif /* CONFIG_H_ */
