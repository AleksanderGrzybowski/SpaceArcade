/*
 * Line.cpp
 *
 *  Created on: 4 kwi 2014
 *      Author: kelog
 */

#include "Line.h"

Line::Line() : shape(sf::Vector2f(CONF_screenWidth, CONF_lineHeight)) {
	shape.setPosition(0, CONF_screenHeight*(1-CONF_enemyDownLimit));
	shape.setFillColor(sf::Color::Yellow);
}
