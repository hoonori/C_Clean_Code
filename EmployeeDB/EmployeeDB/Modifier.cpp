#include "Modifier.h"

Modifier::Modifier(DataBase* dataBase) {
	m_dataBase = dataBase;
}
/*
bool Modifier::employeeSort(const int& index1, const int& index2) {
	int emNum1 = stoi(m_dataBase->ReadRecord(index1).employeeNum);
	int emNum2 = stoi(m_dataBase->ReadRecord(index2).employeeNum);
	int year1 = emNum1 / 1000000;
	int year2 = emNum2 / 1000000;
	int isMillennium1, isMillennium2;

	if (year1 >= 69 && year1 <= 99)
		isMillennium1 = false;
	else
		isMillennium1 = true;

	if (year2 >= 69 && year2 <= 99)
		isMillennium2 = false;
	else
		isMillennium2 = true;

	if (isMillennium1 == false && isMillennium2 == true)
		return true;
	else if (isMillennium1 == true && isMillennium2 == false)
		return false;
	else
		return emNum1 < emNum2;
}
*/

bool Modifier::Modify(KeyType condType, string condData, KeyType modType, string modData, char option1, char option2, char option3) {
	
	KeyType condTypeWithOption = condType;	
	
	//Option 2: Change condType
	if (option2 == 'f' && condType == KeyType::Name)
		condTypeWithOption = KeyType::FirstName;
	else if (option2 == 'l' && condType == KeyType::Name)
		condTypeWithOption = KeyType::LastName;
	else if (option2 == 'm' && condType == KeyType::PhoneNum)
		condTypeWithOption = KeyType::MiddlePhoneNum;
	else if (option2 == 'l' && condType == KeyType::PhoneNum)
		condTypeWithOption = KeyType::LastPhoneNum;
	else if (option2 == 'y' && condType == KeyType::Birthday)
		condTypeWithOption = KeyType::YearBirth;
	else if (option2 == 'm' && condType == KeyType::Birthday)
		condTypeWithOption = KeyType::MonthBirth;
	else if (option2 == 'd' && condType == KeyType::Birthday)
		condTypeWithOption = KeyType::DayBirth;
	else if (option2 != NULL) {
		cout << "get invalid option" << endl;
		return false;
	}

	vector<int> indexVec = m_dataBase->FindMapAll(condTypeWithOption, condData);
	/*
	//Option 1: print matched data
	sort(indexVec.begin(), indexVec.end(), *this);

	if (indexVec.size() == 0)
		printer.PrintNone("MOD");

	else if (option1 == 'p') {
		int maxIter = 5;

		if (indexVec.size() > maxIter)
			maxIter = indexVec.size();
		
		for (int i = 0; i < maxIter; i++) {
			Employee entry = m_dataBase->ReadRecord(indexVec[i]);
			printer.PrintRecord("MOD", entry.employeeNum, entry.name, entry.cl, entry.phoneNum, entry.birthday, entry.certi);
		}
	}
	else
		printer.PrintCount("MOD", indexVec.size());

	*/
	for (auto index : indexVec)
		m_dataBase->UpdateRecord(index, modData, modType);

	return true;
}

