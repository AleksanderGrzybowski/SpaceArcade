#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>

/* Główna konfiguracja gry, nie ma problemu przerobić
 * tego na dynamiczne zmienne jeśli będzie trzeba.
 * Wszystkie zmienne 'chance' wyrażone są w % całkowitych.
 */


// Opcje ogólne
static const int CONF_screenWidth = 400;
static const int CONF_screenHeight = 700;
static const std::string CONF_windowTitle = "SpaceArcade 0.1";
static const int CONF_frameRateLimit = 60;
static const int CONF_difficultyLevel = 1000; // ważne

// Statek
static const int CONF_shipSize = 48; // Potrzebne niestety kilku klasom
static const double CONF_shipUpLimit = 0.2; // Limit poruszania się statku w górę

// Enemy
static const double CONF_enemyDownLimit = 0.3; // Jak szerokie jest miejsce, w którym powstają przeciwnicy.
static const int CONF_enemyGenerationChance = 1;

// Bonus
static const int CONF_bonusGenerationChance = 1;
static const double CONF_bonusDownLimit = 0.3; // Jak szerokie jest miejsce, w którym powstają bonusy.

// Line
static const int CONF_lineHeight = 2; // zwykły prostokąt ograniczający

// TextObject, używana tylko 1 czcionka
static const std::string CONF_fontFile = "Fonts/Arial.ttf";



#endif /* CONFIG_H_ */
