#ifndef FILENOTFOUNDEXCEPTION_H_
#define FILENOTFOUNDEXCEPTION_H_

#include <string>

/* Klasa odpowiedzialna za obsługę braku pliku
 * Typowy 'shall never happen' bo pliki z teksturami na przykład
 * muszą istnieć, ale np. working dir może być inny i lipa
 */
class FileNotFoundException {
public:
	FileNotFoundException(std::string f) : fileName(f) {}
	std::string getFileName() { return fileName; }

private:
	std::string fileName;
};

#endif /* FILENOTFOUNDEXCEPTION_H_ */
