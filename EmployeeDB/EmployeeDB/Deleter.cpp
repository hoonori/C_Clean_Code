#include "Deleter.h"
#include "Parser.h"

#include "DataStructure.h"

Deleter::Deleter(IDataBase* dataBase, IPrinter* printer) {
	m_dataBase = dataBase;
	m_printer = printer;
}

int Deleter::Delete(OptionType option1, OptionType option2, KeyType type, string key)
{
	type = Parser::ChangeCondition(type, option2);

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
		Parser::SortEmployee(deleteList);
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