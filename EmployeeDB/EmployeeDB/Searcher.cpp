#include "Searcher.h"

Searcher::Searcher(DataBase* dataBase) {
	m_dataBase = dataBase;
}

vector<int> Searcher::Search(KeyType keyType, string key)
{
	vector<int> resVec = m_dataBase->FindMapAll(keyType, key);

	return resVec;
}

