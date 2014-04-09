#ifndef RANDOM_H_
#define RANDOM_H_

#include <unistd.h>
#include <time.h>
#include <cstdlib>

class Random {
public:
	static bool getBool();
	static int getInt(int min, int max);
	static bool tryChance(int perc);
private:
	static bool initialized;

};

#endif /* RANDOM_H_ */
