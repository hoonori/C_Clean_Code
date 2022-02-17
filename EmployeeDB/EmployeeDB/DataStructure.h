#pragma once
#include <string>
using namespace std;

#define OUT

struct Employee {
	bool valid;
	string employeeNum;
	string name;
	string cl;
	string phoneNum;
	string birthday;
	string certi;

	string firstName;
	string lastName;

	string middlePhoneNum;
	string lastPhoneNum;

	string yearBirth;
	string monthBirth;
	string dayBirth;
};

struct CmdPacket {
	string cmd;
	string option1;
	string option2;
	string option3;
	string data1;
	string data2;
	string data3;
	string data4;
	string data5;
	string data6;
};

enum class KeyType {
	EmployeeNum,
	Name,
	Cl,
	PhoneNum,
	Birthday,
	Certi,
	FirstName,
	LastName,
	MiddlePhoneNum,
	LastPhoneNum,
	YearBirth,
	MonthBirth,
	DayBirth,

	Count,
};

enum class OptionType {
	p,
	f, // first name, first phoneNum
	l, // last name, last phoneNum
	m, // middle phoneNum, month
	y,
	d,
	none,

	Count,
};