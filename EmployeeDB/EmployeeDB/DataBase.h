#pragma once
#include <map>
#include <vector>
#include <string>

#include "IDataBase.h"
#include "DataStructure.h"

class DataBase : public IDataBase
{
public:
	void CreateRecord(Employee employee) override;
	Employee ReadRecord(int index) override;
	void UpdateRecord(int index, string data, KeyType keyType) override;
	void DeleteRecord(int index) override;
	vector<int> FindMapAll(KeyType keyType, string key) override;
private:
	struct Employee m_memberList[100000];

	multimap<string, int> m_employeeNumMap;
	multimap<string, int> m_nameMap;
	multimap<string, int> m_clMap;
	multimap<string, int> m_phoneNumMap;
	multimap<string, int> m_birthdayMap;
	multimap<string, int> m_certiMap;

	multimap<string, int> m_firstNameMap;
	multimap<string, int> m_lastNameMap;
	multimap<string, int> m_middlePhoneNumMap;
	multimap<string, int> m_lastPhoneNumMap;

	multimap<string, int> m_yearBirthMap;
	multimap<string, int> m_monthBirthMap;
	multimap<string, int> m_dayBirthMap;

	int currentIndex = 0;
};

