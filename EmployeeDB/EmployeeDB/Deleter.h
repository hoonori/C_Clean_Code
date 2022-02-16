#pragma once

#include "DataBase.h"
 
class Deleter
{
public:
	Deleter(DataBase* dataBase);
	int Delete(char option1, char option2, KeyType type, string key);
private:
	DataBase* m_dataBase;
};

