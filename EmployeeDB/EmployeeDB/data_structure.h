#pragma once
#include <map>
#include <string>
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



struct Employee memberList[100000];

multimap<string, int> employeeNum_map;
multimap<string, int> name_map;
multimap<string, int> cl_map;
multimap<string, int> phoneNum_map;
multimap<string, int> birthday_map;
multimap<string, int> certi_map;

int currentIndex = 0;