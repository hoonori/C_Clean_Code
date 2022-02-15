#pragma once

#include "DataBase.h"

class Searcher
{
public:
	Searcher(DataBase* dataBase);

private:
	DataBase* m_dataBase;
};
