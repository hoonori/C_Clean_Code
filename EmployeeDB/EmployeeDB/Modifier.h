#pragma once

#include "DataBase.h"

class Modifier
{
public:
	Modifier(DataBase* dataBase);
	void Modify(KeyType condType, string condData, KeyType modType, string modData);
private:
	DataBase* m_dataBase;
};
