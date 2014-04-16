#ifndef FILENOTFOUNDEXCEPTION_H_
#define FILENOTFOUNDEXCEPTION_H_

#include <string>

class FileNotFoundException {
public:
	std::string fileName;

	FileNotFoundException(std::string f) : fileName(f) {}


};

#endif /* FILENOTFOUNDEXCEPTION_H_ */
