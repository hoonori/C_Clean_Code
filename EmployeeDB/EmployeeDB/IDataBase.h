#pragma once

#include <vector>
#include <string>

#include "DataStructure.h"

class IDataBase
{
public:
	virtual void CreateRecord(Employee employee) = 0;
	virtual Employee ReadRecord(int index) = 0;
	virtual void UpdateRecord(int index, string data, KeyType keyType) = 0;
	virtual void DeleteRecord(int index) = 0;
	virtual vector<int> FindMapAll(KeyType keyType, string key) = 0;
private:
};