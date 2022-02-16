#include "Modifier.h"
#include "DataStructure.h"

Modifier::Modifier(DataBase* dataBase) {
	m_dataBase = dataBase;
}

void Modifier::Modify(KeyType condType, string condData, KeyType modType, string modData) {
	
	vector<int> indexVec = m_dataBase->FindMapAll(condType, condData);

	for (auto index : indexVec) {
		m_dataBase->UpdateRecord(index, modData, modType);
	}
}