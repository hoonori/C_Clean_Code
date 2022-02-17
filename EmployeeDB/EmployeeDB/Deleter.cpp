#include "Deleter.h"

#include "DataStructure.h"

Deleter::Deleter(DataBase* dataBase) {
	m_dataBase = dataBase;
}

Deleter::Deleter(DataBase* dataBase, Printer* printer, Parser* parser) {
	m_dataBase = dataBase;
	m_printer = printer;
	m_parser = parser;
}

int Deleter::Delete(OptionType option1, OptionType option2, KeyType type, string key)
{
	switch (option2) {
	case OptionType::f :
		if (type == KeyType::Name) {
			type = KeyType::FirstName;
		}
		else { return -1; }
		break;
	case OptionType::l :
		if (type == KeyType::Name) {
			type = KeyType::LastName;
		}
		else if (type == KeyType::PhoneNum) {
			type = KeyType::LastPhoneNum;
		}
		else { return -1; }
		break;
	case OptionType::m :
		if (type == KeyType::PhoneNum) {
			type = KeyType::MiddlePhoneNum;
		}
		else if (type == KeyType::Birthday) {
			type = KeyType::MonthBirth;
		}
		else { return -1; }
		break;
	case OptionType::y :
		if (type == KeyType::Birthday) {
			type = KeyType::YearBirth;
		}
		else { return -1; }
		break;
	case OptionType::d :
		if (type == KeyType::Birthday) {
			type = KeyType::DayBirth;
		}
		else { return -1; }
		break;
	case OptionType::none :
		break;
	default:
		return -1;
	}

	vector<Employee> deleteList;
	vector<int> list = 	m_dataBase->FindMapAll(type, key);
	int count = 0;
	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		if (m_dataBase->ReadRecord(*iter).valid)
		{
			deleteList.push_back(m_dataBase->ReadRecord(*iter));
			count++;
			m_dataBase->DeleteRecord(*iter);
		}
	}
	
	if (count == 0)
	{
		m_printer->PrintNone("DEL");
	}
	else if (option1 == OptionType::p)
	{
		m_parser->SortEmployee(deleteList);
		int printed = 0;
		for (auto iter = deleteList.begin(); iter != deleteList.end(); iter++)
		{
			if (printed >= 5) break;
			m_printer->PrintRecord("DEL", iter->employeeNum, iter->name, iter->cl, iter->phoneNum, iter->birthday, iter->certi);
			printed++;
		}
	}
	else
	{
		m_printer->PrintCount("DEL", count);
	}
	
	return count;
}