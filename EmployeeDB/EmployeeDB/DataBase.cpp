#include "DataBase.h"

void DataBase::CreateRecord(Employee employee) {
	m_memberList[currentIndex] = employee;

	m_employeeNumMap.insert({ employee.employeeNum, currentIndex });
	m_nameMap.insert({ employee.name, currentIndex });
	m_clMap.insert({ employee.cl, currentIndex });
	m_phoneNumMap.insert({ employee.phoneNum, currentIndex });
	m_birthdayMap.insert({ employee.birthday, currentIndex });
	m_certiMap.insert({ employee.certi, currentIndex });

	m_firstNameMap.insert({ employee.firstName, currentIndex });
	m_lastNameMap.insert({ employee.lastName, currentIndex });
	m_middlePhoneNumMap.insert({ employee.middlePhoneNum, currentIndex });
	m_lastPhoneNumMap.insert({ employee.lastPhoneNum, currentIndex });

	m_yearBirthMap.insert({ employee.yearBirth, currentIndex });
	m_monthBirthMap.insert({ employee.monthBirth, currentIndex });
	m_dayBirthMap.insert({ employee.dayBirth, currentIndex });

	currentIndex++;
}

Employee DataBase::ReadRecord(int index) {
	return m_memberList[index];
}
void DataBase::UpdateRecord(int index, string data, KeyType keyType) {

	multimap<string, int>* pMap = nullptr;
	string formerData;
	string employNum = m_memberList[index].employeeNum;

	// Update DB and find chaning key-based Map
	switch (keyType) {
	case KeyType::EmployeeNum:
		pMap = &m_employeeNumMap;
		formerData = m_memberList[index].employeeNum;
		m_memberList[index].employeeNum = data;
		break;
	case KeyType::Name:
		pMap = &m_nameMap;
		formerData = m_memberList[index].name;
		m_memberList[index].name = data;
		break;
	case KeyType::Cl:
		pMap = &m_clMap;
		formerData = m_memberList[index].cl;
		m_memberList[index].cl = data;
		break;
	case KeyType::PhoneNum:
		pMap = &m_phoneNumMap;
		formerData = m_memberList[index].phoneNum;
		m_memberList[index].phoneNum = data;
		break;
	case KeyType::Birthday:
		pMap = &m_birthdayMap;
		formerData = m_memberList[index].birthday;
		m_memberList[index].birthday = data;
		break;
	case KeyType::Certi:
		pMap = &m_certiMap;
		formerData = m_memberList[index].certi;
		m_memberList[index].certi = data;
		break;
	case KeyType::FirstName:
		pMap = &m_firstNameMap;
		formerData = m_memberList[index].firstName;
		m_memberList[index].firstName = data;
		break;
	case KeyType::LastName:
		pMap = &m_lastNameMap;
		formerData = m_memberList[index].lastName;
		m_memberList[index].lastName = data;
		break;
	case KeyType::MiddlePhoneNum:
		pMap = &m_middlePhoneNumMap;
		formerData = m_memberList[index].middlePhoneNum;
		m_memberList[index].middlePhoneNum = data;
		break;
	case KeyType::LastPhoneNum:
		pMap = &m_lastPhoneNumMap;
		formerData = m_memberList[index].lastPhoneNum;
		m_memberList[index].lastPhoneNum = data;
		break;
	case KeyType::YearBirth:
		pMap = &m_yearBirthMap;
		formerData = m_memberList[index].yearBirth;
		m_memberList[index].yearBirth = data;
		break;
	case KeyType::MonthBirth:
		pMap = &m_monthBirthMap;
		formerData = m_memberList[index].monthBirth;
		m_memberList[index].monthBirth = data;
		break;
	case KeyType::DayBirth:
		pMap = &m_dayBirthMap;
		formerData = m_memberList[index].dayBirth;
		m_memberList[index].dayBirth = data;
		break;
	}

	// Update changed key-based Map
	for (auto iter = pMap->lower_bound(formerData); iter != pMap->upper_bound(formerData); iter++) {
		int listIndex = iter->second;
		
		// update Map and break loop
		if (listIndex == index) {
			pMap->erase(iter);
			pMap->insert({ data, index });
			break;
		}
	}
}

void DataBase::DeleteRecord(int index) {
	m_memberList[index].valid = false;
}

vector<int> DataBase::FindMapAll(KeyType keyType, string key) {
	vector<int> vector;

	multimap<string, int>* pMap = nullptr;

	switch (keyType) {
	case KeyType::EmployeeNum:
		pMap = &m_employeeNumMap;
		break;
	case KeyType::Name:
		pMap = &m_nameMap;
		break;
	case KeyType::Cl:
		pMap = &m_clMap;
		break;
	case KeyType::PhoneNum:
		pMap = &m_phoneNumMap;
		break;
	case KeyType::Birthday:
		pMap = &m_birthdayMap;
		break;
	case KeyType::Certi:
		pMap = &m_certiMap;
		break;
	case KeyType::FirstName:
		pMap = &m_firstNameMap;
		break;
	case KeyType::LastName:
		pMap = &m_lastNameMap;
		break;
	case KeyType::MiddlePhoneNum:
		pMap = &m_middlePhoneNumMap;
		break;
	case KeyType::LastPhoneNum:
		pMap = &m_lastPhoneNumMap;
		break;
	case KeyType::YearBirth:
		pMap = &m_yearBirthMap;
		break;
	case KeyType::MonthBirth:
		pMap = &m_monthBirthMap;
		break;
	case KeyType::DayBirth:
		pMap = &m_dayBirthMap;
		break;
	}
	
	for (auto iter = pMap->lower_bound(key); iter != pMap->upper_bound(key); iter++) {
		int index = iter->second;
		if (m_memberList[index].valid == true) {
			vector.push_back(index);
		}
	}
	
	return vector;
}