#pragma once

#include "DataBase.h"

class Searcher
{
public:
	Searcher(DataBase* dataBase);
	vector<int> Search(KeyType keyType, string key);

private:
	DataBase* m_dataBase;
};
