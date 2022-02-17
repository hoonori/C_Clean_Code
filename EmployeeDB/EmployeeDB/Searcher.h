#pragma once

#include "DataBase.h"
#include "Printer.h"
#include <Algorithm>
#include "Parser.h"

class Searcher
{
public:
	Searcher(DataBase* dataBase, Printer* printer);
	bool Search(KeyType keyType, string key, OptionType ot, OptionType ot2);
	bool isNumber(const string& str);

private:
	DataBase* m_dataBase;
	Printer* m_Printer;
	string m_comm;

	bool CallPrinter(Employee employee);
};
