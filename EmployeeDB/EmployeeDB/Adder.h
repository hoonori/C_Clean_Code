#pragma once
#include <string>

#include "IDataBase.h"

class Adder
{
public:
	Adder(IDataBase* dataBase);
	void Add(string employeeNum, string name, string cl, string phoneNum, string birthday, string certi);
private:
	IDataBase* m_dataBase;
};