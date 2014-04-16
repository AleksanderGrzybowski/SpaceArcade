#include "fileExists.h"

bool fileExists(std::string fname) {
	std::ifstream s(fname);
	return s.good();
}
