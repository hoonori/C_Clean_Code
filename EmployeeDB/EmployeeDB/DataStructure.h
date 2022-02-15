#pragma once
#include <string>
using namespace std;


struct Employee {
	bool valid;
	string employeeNum;
	string name;
	string cl;
	string phoneNum;
	string birthday;
	string certi;
};

enum class KeyType {
	EmployeeNum,
	Name,
	Cl,
	PhoneNum,
	Birthday,
	Certi,
};