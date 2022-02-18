#pragma once

#include "IDataBase.h"
#include "IPrinter.h"
#include <Algorithm>
#include "Parser.h"

class Searcher
{
public:
	Searcher(IDataBase* dataBase, IPrinter* printer);
	bool Search(KeyType keyType, string key, OptionType ot, OptionType ot2);
	bool isNumber(const string& str);

private:
	IDataBase* m_dataBase;
	IPrinter* m_Printer;
	string m_comm;

	bool CallPrinter(Employee employee);
};
