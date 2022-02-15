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
};