#pragma once

#include "DataBase.h"
#include "Printer.h"
 
class Deleter
{
public:
	Deleter(IDataBase* dataBase, IPrinter* printer);
	int Delete(OptionType option1, OptionType option2, KeyType type, string key);
private:
	IDataBase* m_dataBase;
	IPrinter* m_printer;
};

