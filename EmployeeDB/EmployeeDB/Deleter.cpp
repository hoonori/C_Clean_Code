#include "Deleter.h"

#include "DataStructure.h"

Deleter::Deleter(DataBase* dataBase) {
	m_dataBase = dataBase;
}

int Deleter::Delete(char option1, char option2, KeyType type, string key)
{
	vector<int> list = 	m_dataBase->FindMapAll(type, key);
	int count = 0;
	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		if (m_dataBase->ReadRecord(*iter).valid)
		{
			count++;
			m_dataBase->DeleteRecord(*iter);
		}
	}
	return count;
}