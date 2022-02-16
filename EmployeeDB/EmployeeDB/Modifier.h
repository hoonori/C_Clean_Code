#pragma once
#include <algorithm>
#include <iostream>

#include "DataBase.h"
#include "Printer.h"
#include "DataStructure.h"

class Modifier
{
public:
	Modifier(DataBase* dataBase);
	bool Modify(KeyType condType, string condData, KeyType modType, string modData, char option1, char option2, char option3);
	DataBase* m_dataBase;
	bool employeeSort(const int& index1, const int& index2);
};
