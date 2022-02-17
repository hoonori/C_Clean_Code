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
#include "Printer.h"


int main(int argc, char* argv[]) {

	string inputFileName = argv[1];
	string outputFileName = argv[2];
	ifstream ifs;
	ofstream ofs;

	ifs.open(inputFileName);
	ofs.open(outputFileName);

	Printer* printer = new Printer(&ofs);
	Parser* parser = new Parser;
	DataBase* database = new DataBase();
	Adder* adder = new Adder(database);
	Deleter* deleter = new Deleter(database, printer);
	Searcher* searcher = new Searcher(database, printer);
	Modifier* modifier = new Modifier(database, printer);

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
				OptionType option1 = Parser::ParseOption(cmdPacket.option1);
				OptionType option2 = Parser::ParseOption(cmdPacket.option2);
				KeyType keyType = Parser::TranslateKeyType(cmdPacket.data1);
				string keyData = cmdPacket.data2;

				deleter->Delete(option1, option2, keyType, keyData);
			}
			else if (cmdPacket.cmd.compare("SCH") == 0) {
				OptionType option1 = Parser::ParseOption(cmdPacket.option1);
				OptionType option2 = Parser::ParseOption(cmdPacket.option2);
				KeyType keyType = Parser::TranslateKeyType(cmdPacket.data1);
				string keyData = cmdPacket.data2;

				searcher->Search(keyType, keyData, option1, option2);
			}
			else if (cmdPacket.cmd.compare("MOD") == 0) {
				OptionType option1 = Parser::ParseOption(cmdPacket.option1);
				OptionType option2 = Parser::ParseOption(cmdPacket.option2);
				KeyType keyType = Parser::TranslateKeyType(cmdPacket.data1);
				string keyData = cmdPacket.data2;
				KeyType modType = Parser::TranslateKeyType(cmdPacket.data3);
				string modData = cmdPacket.data4;

				modifier->Modify(keyType, keyData, modType, modData, option1, option2);
			}
			else {
				// cout << "[Fail] wrong command input" << endl;
				break;
			}
		}
	}
	else {
		// cout << "[Fail] File does not exists" << endl;
	}

	ifs.close();
	ofs.close();
	return 0;
}
