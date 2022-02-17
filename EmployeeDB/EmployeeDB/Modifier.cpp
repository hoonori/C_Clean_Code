#include "Modifier.h"

Modifier::Modifier(DataBase* dataBase, Printer* printer) {
	m_dataBase = dataBase;
	m_printer = printer;
}

bool Modifier::Modify(KeyType condType, string condData, KeyType modType, string modData, OptionType option1, OptionType option2) {
	
	KeyType condTypeWithOption = condType;	
	Parser parser;
	vector<Employee> sortedEmployee;

	//Option 2: Change condType
	if (option2 == OptionType::f && condType == KeyType::Name)
		condTypeWithOption = KeyType::FirstName;
	else if (option2 == OptionType::l && condType == KeyType::Name)
		condTypeWithOption = KeyType::LastName;
	else if (option2 == OptionType::m && condType == KeyType::PhoneNum)
		condTypeWithOption = KeyType::MiddlePhoneNum;
	else if (option2 == OptionType::l && condType == KeyType::PhoneNum)
		condTypeWithOption = KeyType::LastPhoneNum;
	else if (option2 == OptionType::y && condType == KeyType::Birthday)
		condTypeWithOption = KeyType::YearBirth;
	else if (option2 == OptionType::m && condType == KeyType::Birthday)
		condTypeWithOption = KeyType::MonthBirth;
	else if (option2 == OptionType::d && condType == KeyType::Birthday)
		condTypeWithOption = KeyType::DayBirth;

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
		m_dataBase->UpdateRecord(index, modData, modType);

	return true;
}

