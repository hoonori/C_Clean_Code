#pragma once
#include <string>

#include "DataBase.h"

class Adder
{
public:
	Adder(DataBase* dataBase);
	void Add(string employeeNum, string name, string cl, string phoneNum, string birthday, string certi);
private:
	DataBase* m_dataBase;
};