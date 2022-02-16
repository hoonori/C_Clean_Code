#pragma once

#include "DataBase.h"
#include "Printer.h"
#include <Algorithm>

using namespace std;

enum class OptType
{
	NONE,
	Printer,
	FirstName,
	LastName,
	MiddlePhoneNum,
	LastPhoneNum,
	YearBirth,
	MonthBirth,
	DayBirth,
};
class Searcher
{
public:
	Searcher(DataBase* dataBase, Printer* printer);
	vector<int> Search(KeyType keyType, string key);
	bool CallPrinter(Employee employee);

private:
	DataBase* m_dataBase;
	Printer* m_Printer;
	string m_comm;
};
