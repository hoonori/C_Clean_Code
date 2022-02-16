#pragma once

#include "DataBase.h"

class Modifier
{
public:
	Modifier(DataBase* dataBase);

private:
	DataBase* m_dataBase;
};
