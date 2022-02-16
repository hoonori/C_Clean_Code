#include <sstream>
#include <iostream>

#include "Parser.h"

void Parser::Parse(string line, OUT CmdPacket& cmdPacket) {

	char token = ',';
	stringstream sstream(line);

	string word;
	int wordIndex = 0;
	int functionIndex = 0;
	while (getline(sstream, word, token)) {

		if (wordIndex == 0) {
			cmdPacket.cmd = word;
		}
		else if (wordIndex == 1) {
			cmdPacket.option1 = word;
		}
		else if (wordIndex == 2) {
			cmdPacket.option2 = word;
		}
		else if (wordIndex == 3) {
			cmdPacket.option3 = word;
		}
		else if (wordIndex == 4) {
			cmdPacket.data1 = word;
		}
		else if (wordIndex == 5) {
			cmdPacket.data2 = word;
		}
		else if (wordIndex == 6) {
			cmdPacket.data3 = word;
		}
		else if (wordIndex == 7) {
			cmdPacket.data4 = word;
		}
		else if (wordIndex == 8) {
			cmdPacket.data5 = word;
		}
		else if (wordIndex == 9) {
			cmdPacket.data6 = word;
		}
		else {
			cout << "[Fail] intput data format error" << endl;
		}

		wordIndex++;
	}
}