#pragma once

#include "DataBase.h"
#include "Printer.h"
#include "Parser.h"
 
class Deleter
{
public:
	Deleter(DataBase* dataBase);
	Deleter(DataBase* dataBase, Printer* printer, Parser* parser);
	int Delete(OptionType option1, OptionType option2, KeyType type, string key);
private:
	DataBase* m_dataBase;
	Printer* m_printer;
	Parser* m_parser;
};

