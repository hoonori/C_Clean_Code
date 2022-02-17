#pragma once

#include "DataBase.h"
#include "Printer.h"
 
class Deleter
{
public:
	Deleter(DataBase* dataBase, Printer* printer);
	int Delete(OptionType option1, OptionType option2, KeyType type, string key);
private:
	DataBase* m_dataBase;
	Printer* m_printer;
};

