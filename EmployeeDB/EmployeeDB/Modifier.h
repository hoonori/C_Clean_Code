#pragma once
#include <algorithm>
#include <iostream>

#include "DataBase.h"
#include "Printer.h"
#include "DataStructure.h"
#include "Parser.h"

class Modifier
{
public:
	Modifier(DataBase* dataBase, Printer* m_printer);
	bool Modify(KeyType condType, string condData, KeyType modType, string modData, OptionType option1, OptionType option2);
	DataBase* m_dataBase;
	Printer* m_printer;
};
