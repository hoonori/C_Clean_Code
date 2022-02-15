#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#define MAXTYPE 6
#define MAX_MEMBER 100000
using namespace std;


struct Employee {
	int valid;
	string employeeNum;
	string name;
	string cl;
	string phoneNum;
	string birthday;
	string certi;
};

enum datatype {
	EMPLOYEENUM,
	NAME,
	CL,
	PHONENUM,
	BIRTHDAY,
	CERTI
};

struct Employee memberList[MAX_MEMBER];

multimap<string, int> employeeNum_map;
multimap<string, int> name_map;
multimap<string, int> cl_map;
multimap<string, int> phoneNum_map;
multimap<string, int> birthday_map;
multimap<string, int> certi_map;

