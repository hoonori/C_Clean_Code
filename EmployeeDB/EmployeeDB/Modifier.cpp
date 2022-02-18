#include "Modifier.h"

Modifier::Modifier(IDataBase* dataBase, IPrinter* printer) {
	m_dataBase = dataBase;
	m_printer = printer;
}

bool Modifier::Modify(KeyType condType, string condData, KeyType modType, string modData, OptionType option1, OptionType option2) {
	
	KeyType condTypeWithOption = Parser::ChangeCondition(condType, option2);
	Parser parser;
	vector<Employee> sortedEmployee;

	vector<int> indexVec = m_dataBase->FindMapAll(condTypeWithOption, condData);
	
	//Option 1: print matched data
	for (auto index : indexVec)
		sortedEmployee.emplace_back(m_dataBase->ReadRecord(index));

	Parser::SortEmployee(sortedEmployee);
	
	if (sortedEmployee.size() == 0)
		m_printer->PrintNone("MOD");

	else if (option1 == OptionType::p) {
		int maxIter = 5;

		if (sortedEmployee.size() < maxIter)
			maxIter = sortedEmployee.size();
		
		for (int i = 0; i < maxIter; i++) {
			Employee entry = sortedEmployee[i];
			m_printer->PrintRecord("MOD", entry.employeeNum, entry.name, entry.cl, entry.phoneNum, entry.birthday, entry.certi);
		}
	}
	else
		m_printer->PrintCount("MOD", sortedEmployee.size());

	//Updata Record
	for (auto index : indexVec)
	{
		m_dataBase->UpdateRecord(index, modData, modType);
		if (modType == KeyType::Name) {
			string firstName;
			string lastName;

			Parser::ParseName(modData, firstName, lastName);

			m_dataBase->UpdateRecord(index, firstName, KeyType::FirstName);
			m_dataBase->UpdateRecord(index, lastName, KeyType::LastName);
		}
		else if (modType == KeyType::PhoneNum) {
			string middlePhoneNum;
			string lastPhoneNum;

			Parser::ParsePhoneNum(modData, middlePhoneNum, lastPhoneNum);

			m_dataBase->UpdateRecord(index, middlePhoneNum, KeyType::MiddlePhoneNum);
			m_dataBase->UpdateRecord(index, lastPhoneNum, KeyType::LastPhoneNum);
		}
		else if (modType == KeyType::Birthday) {
			string yearBirth;
			string monthBirth;
			string dayBirth;

			Parser::ParseBirthDay(modData, yearBirth, monthBirth, dayBirth);

			m_dataBase->UpdateRecord(index, yearBirth, KeyType::YearBirth);
			m_dataBase->UpdateRecord(index, monthBirth, KeyType::MonthBirth);
			m_dataBase->UpdateRecord(index, dayBirth, KeyType::DayBirth);
		}
	}

	return true;
}

