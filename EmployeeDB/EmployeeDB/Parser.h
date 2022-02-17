#pragma once

#include <string>
#include <vector>
#include "DataStructure.h"

using namespace std;

class Parser
{
public:
	static void ParseCmdLine(string line, OUT CmdPacket& cmdPacket);
	static void ParseName(string name, OUT string& firstName, string& lastName);
	static void ParsePhoneNum(string phoneNum, OUT string& middlePhoneNum, OUT string& lastPhoneNum);
	static void ParseBirthDay(string birthDay, OUT string& year, OUT string& month, OUT string& day);
	static OptionType ParseOption(string option);
	static void SortEmployee(OUT vector<Employee>& employVec);
	static KeyType TranslateKeyType(string keyname);
	static KeyType ChangeCondition(KeyType key, OptionType option);
private:
};

