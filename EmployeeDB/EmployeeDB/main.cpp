#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Parser.h"


int main(int argc, char* argv[]) {

	string inputFileName = argv[1];
	string outputFileName = argv[2];
	ifstream ifs;
	ofstream ofs;

	ifs.open(inputFileName);
	ofs.open(outputFileName);

	Parser parser;

	if (!ifs.fail()) {
		string line;
		while (getline(ifs, line)) {
			cout << line << endl;

			int functionIndex = parser.Parse(line);

			switch (functionIndex) {
			case 0:
				// do Add function
				break;
			case 1:
				// do DEL function
				break;
			case 2:
				// do SCH function
				break;
			case 3:
				// do MOD function
				break;
			}
		}
	}
	else {
		cout << "[Fail] File does not exists" << endl;
	}
	return 0;
}
