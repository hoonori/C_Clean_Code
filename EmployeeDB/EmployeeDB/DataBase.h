#pragma once
#include <map>
#include <vector>
#include <string>

#include "DataStructure.h"

class DataBase
{
public:
	void CreateRecord(Employee employee);
	Employee ReadRecord(int index);
	void UpdateRecord(int index, Employee employee);
	void DeleteRecord(int index);

	vector<int> FindAll(KeyType keyType, string key);
private:
	struct Employee memberList[100000];

	multimap<string, int> employeeNum_map;
	multimap<string, int> name_map;
	multimap<string, int> cl_map;
	multimap<string, int> phoneNum_map;
	multimap<string, int> birthday_map;
	multimap<string, int> certi_map;

	int currentIndex = 0;
};

