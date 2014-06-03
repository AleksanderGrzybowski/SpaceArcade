#ifndef RANDOM_H_
#define RANDOM_H_

#include <unistd.h>
#include <time.h>
#include <cstdlib>

/* Prosta klasa do losowania liczb z danego zakresu
 * oraz losowania prawdopodobieństw.
 */
class Random {
public:

	static bool getBool();
	static int getInt(int min, int max);
	static bool tryChance(double perc);

private:
	static bool initialized;
};

#endif /* RANDOM_H_ */
