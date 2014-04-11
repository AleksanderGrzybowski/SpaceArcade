#include "Random.h"

bool Random::getBool() {
	if (!initialized) {
		srand(time(0));
		initialized = true;
	}
	return (rand() % 2) == 0;
}

int Random::getInt(int min, int max) {
	if (!initialized) {
		srand(time(0));
		initialized = true;
	}
	return rand()%(max-min+1)+min;
}

bool Random::tryChance(double prob) { // prob <0..100>
	int l = getInt(0, 100);
	if (prob > l) return true;
	else return false;

}

bool Random::initialized = false;
