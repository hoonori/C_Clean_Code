#include "Deleter.h"

#include "DataStructure.h"

Deleter::Deleter(DataBase* dataBase) {
	m_dataBase = dataBase;
}

int Deleter::Delete(char option1, char option2, KeyType type, string key)
{
	if (option2 != 0)
	{
		switch (option2) {
		case 'f':
			if (type == KeyType::Name) {
				type = KeyType::FirstName;
			}
			else { return -1; }
			break;
		case 'l':
			if (type == KeyType::Name) {
				type = KeyType::LastName;
			}
			else if (type == KeyType::PhoneNum) {
				type = KeyType::LastPhoneNum;
			}
			else { return -1; }
			break;
		case 'm':
			if (type == KeyType::PhoneNum) {
				type = KeyType::MiddlePhoneNum;
			}
			else if (type == KeyType::Birthday) {
				type = KeyType::MonthBirth;
			}
			else { return -1; }
			break;
		case 'y':
			if (type == KeyType::Birthday) {
				type = KeyType::YearBirth;
			}
			else { return -1; }
			break;
		case 'd':
			if (type == KeyType::Birthday) {
				type = KeyType::DayBirth;
			}
			else { return -1; }
			break;
		default:
			return -1;
		}
	}

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