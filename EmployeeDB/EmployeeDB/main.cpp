#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Parser.h"
#include "Adder.h"
#include "Deleter.h"
#include "Searcher.h"
#include "Modifier.h"

int main(int argc, char* argv[]) {

	string inputFileName = argv[1];
	string outputFileName = argv[2];
	ifstream ifs;
	ofstream ofs;

	ifs.open(inputFileName);
	ofs.open(outputFileName);

	DataBase* database = new DataBase();
	Adder* adder = new Adder(database);
	Deleter* deleter = new Deleter(database);
	Searcher* searcher = new Searcher(database);
	Modifier* modifier = new Modifier(database);

	if (!ifs.fail()) {
		string line;
		while (getline(ifs, line)) {
			cout << line << endl;
			CmdPacket cmdPacket;
			Parser::ParseCmdLine(line, cmdPacket);

			if (cmdPacket.cmd.compare("ADD") == 0) {
				string employNum = cmdPacket.data1;
				string name = cmdPacket.data2;
				string cl = cmdPacket.data3;
				string phoneNumber = cmdPacket.data4;
				string birthday = cmdPacket.data5;
				string certi = cmdPacket.data6;

				adder->Add(employNum, name, cl, phoneNumber, birthday, certi);
			}
			else if (cmdPacket.cmd.compare("DEL") == 0) {

			}
			else if (cmdPacket.cmd.compare("SCH") == 0) {

			}
			else if (cmdPacket.cmd.compare("MOD") == 0) {

			}
			else {
				cout << "[Fail] wrong command input" << endl;
				break;
			}
		}
	}
	else {
		cout << "[Fail] File does not exists" << endl;
	}
	return 0;
}
