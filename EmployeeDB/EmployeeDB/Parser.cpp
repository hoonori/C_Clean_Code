#include <sstream>
#include <iostream>
#include <algorithm>

#include "Parser.h"

bool compare(Employee a, Employee b) {
	int a_employeeNum = stoi(a.employeeNum);
	int b_employeeNum = stoi(b.employeeNum);

	bool greator;

	constexpr int YOUNGEST_EMPLOYEE_NUM = 21999999;
	constexpr int OLDEST_EMPLOYEE_NUM = 69000000;

	
	// case 1 : if both are before 2000s, smaller integer is older
	if (a_employeeNum >= OLDEST_EMPLOYEE_NUM && b_employeeNum >= OLDEST_EMPLOYEE_NUM) {
		greator = a_employeeNum < b_employeeNum;
	}
	// case 2 : if both are after 2000s, smaller integer is older
	else if (a_employeeNum <= YOUNGEST_EMPLOYEE_NUM && b_employeeNum <= YOUNGEST_EMPLOYEE_NUM) {
		greator = a_employeeNum < b_employeeNum;
	}
	// case 3 : if a is after 2000s, and b is before 2000s, b is older
	else if (a_employeeNum <= YOUNGEST_EMPLOYEE_NUM && b_employeeNum >= OLDEST_EMPLOYEE_NUM) {
		greator = false;
	}
	// case 4 : if a is before 2000s, and b is after 2000s, a is older
	else if (a_employeeNum >= OLDEST_EMPLOYEE_NUM && b_employeeNum <= YOUNGEST_EMPLOYEE_NUM) {
		greator = true;
	}
	else {
		cout << "[Fail] wrong EmployNum Range" << endl;
	}

	return greator;
}


void Parser::ParseCmdLine(string line, OUT CmdPacket& cmdPacket) {

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
			cout << "[Fail] intput data Cmd format error" << endl;
		}

		wordIndex++;
	}
}

void Parser::ParseName(string name, OUT string& firstName, string& lastName) {
	char token = ' ';
	stringstream sstream(name);

	string word;
	int wordIndex = 0;
	while (getline(sstream, word, token)) {

		if (wordIndex == 0) {
			firstName = word;
		}
		else if (wordIndex == 1) {
			lastName = word;
		}
		else {
			cout << "[Fail] intput data Name format error" << endl;
		}
		wordIndex++;
	}
}

void Parser::ParsePhoneNum(string phoneNum, OUT string& middlePhoneNum, OUT string& lastPhoneNum) {
	char token = '-';
	stringstream sstream(phoneNum);

	string word;
	int wordIndex = 0;
	while (getline(sstream, word, token)) {

		if (wordIndex == 0) {
			// for debug, do nothing
		}
		else if (wordIndex == 1) {
			middlePhoneNum = word;
		}
		else if (wordIndex == 2) {
			lastPhoneNum = word;
		}
		else {
			cout << "[Fail] intput data PhoneNum format error" << endl;
		}
		wordIndex++;
	}
}

void Parser::ParseBirthDay(string birthDay, OUT string& year, OUT string& month, OUT string& day) {


	for (int index = 0; index < birthDay.size(); index++) {
		char ch = birthDay.at(index);

		if (index <= 3) {
			year += ch;
		}
		else if (index <= 5) {
			month += ch;
		}
		else if (index <= 7) {
			day += ch;
		}
		else {
			cout << "[Fail] intput data BirthDay format error" << endl;
		}
	}
}

OptionType Parser::ParseOption(string option) {
	
	OptionType optionType = OptionType::Count;

	if (option.compare("-p") == 0) {
		optionType = OptionType::p;
	}
	else if (option.compare("-f") == 0) {
		optionType = OptionType::f;
	}
	else if (option.compare("-l") == 0) {
		optionType = OptionType::l;
	}
	else if (option.compare("-m") == 0) {
		optionType = OptionType::m;
	}
	else if (option.compare("-y") == 0) {
		optionType = OptionType::y;
	}
	else if (option.compare("-d") == 0) {
		optionType = OptionType::d;
	}
	else if (option.compare(" ") == 0) {
		optionType = OptionType::none;
	}
	else {
		cout << "[Fail] intput data Option format error" << endl;
	}

	return optionType;
}

void Parser::SortEmployee(OUT vector<Employee>& employVec) {
	sort(employVec.begin(), employVec.end(), compare);
}

KeyType Parser::TranslateKeyType(string keyname) {
	KeyType keyType = KeyType::Count;

	if (keyname.compare("employeeNum") == 0) {
		keyType = KeyType::EmployeeNum;
	}
	else if (keyname.compare("name") == 0) {
		keyType = KeyType::Name;
	}
	else if (keyname.compare("cl") == 0) {
		keyType = KeyType::Cl;
	}
	else if (keyname.compare("phoneNum") == 0) {
		keyType = KeyType::PhoneNum;
	}
	else if (keyname.compare("birthday") == 0) {
		keyType = KeyType::Birthday;
	}
	else if (keyname.compare("certi") == 0) {
		keyType = KeyType::Certi;
	}
	else {
		cout << "[Fail] wrong key name" << endl;
	}

	return keyType;
}

KeyType Parser::ChangeCondition(KeyType key, OptionType option) {
	if (option == OptionType::f && key == KeyType::Name)
		key = KeyType::FirstName;
	else if (option == OptionType::l && key == KeyType::Name)
		key = KeyType::LastName;
	else if (option == OptionType::m && key == KeyType::PhoneNum)
		key = KeyType::MiddlePhoneNum;
	else if (option == OptionType::l && key == KeyType::PhoneNum)
		key = KeyType::LastPhoneNum;
	else if (option == OptionType::y && key == KeyType::Birthday)
		key = KeyType::YearBirth;
	else if (option == OptionType::m && key == KeyType::Birthday)
		key = KeyType::MonthBirth;
	else if (option == OptionType::d && key == KeyType::Birthday)
		key = KeyType::DayBirth;

	return key;
}