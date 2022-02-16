#include "Deleter.h"

#include "DataStructure.h"

Deleter::Deleter(DataBase* dataBase) {
	m_dataBase = dataBase;
}

int Deleter::Delete(char option1, char option2, int type, string key)
{
	return -1;
}