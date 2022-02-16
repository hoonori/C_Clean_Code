#pragma once

#include "DataBase.h"
 
class Deleter
{
public:
	Deleter(DataBase* dataBase);

private:
	DataBase* m_dataBase;
};

