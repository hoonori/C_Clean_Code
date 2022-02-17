#pragma once
#include <algorithm>
#include <iostream>

#include "IDataBase.h"
#include "IPrinter.h"
#include "DataStructure.h"
#include "Parser.h"

class Modifier
{
public:
	Modifier(IDataBase* dataBase, IPrinter* m_printer);
	bool Modify(KeyType condType, string condData, KeyType modType, string modData, OptionType option1, OptionType option2);
	IDataBase* m_dataBase;
	IPrinter* m_printer;
};
