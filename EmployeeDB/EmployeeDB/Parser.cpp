#include <sstream>
#include <iostream>

#include "Parser.h"

int Parser::Parse(string line) {
	
	char token = ',';
	stringstream sstream(line);

	string word;
	int wordIndex = 0;
	int functionIndex = 0;
	while (getline(sstream, word, token)) {

		if (wordIndex == 0) {
			if (word.compare("ADD") == 0) {
				functionIndex = 0;
			}
			else if (word.compare("DEL") == 0) {
				functionIndex = 1;
			}
			else if (word.compare("SCH") == 0) {
				functionIndex = 2;
			}
			else if (word.compare("MOD") == 0) {
				functionIndex = 3;
			}
			else {
				cout << "Fail" << endl;
			}
		}
		wordIndex++;
	}

	return functionIndex;
}