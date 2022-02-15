#include "Deleter.h"
#include "data_structure.h"
#include <map>

int Deleter::Delete(int category, string key)
{
	multimap<string, int>* target;
	int count = 0;
	int index = -1;

	switch (category)
	{
	case 0:
		target = &employeeNum_map;
		break;
	case 1:
		target = &name_map;
		break;
	case 2:
		target = &cl_map;
		break;
	case 3:
		target = &phoneNum_map;
		break;
	case 4:
		target = &birthday_map;
		break;
	case 5:
		target = &certi_map;
		break;
	default:
		return -1;
		break;
	}

	multimap<string, int>::iterator current;
	for (auto current : *target)
	{
		if (current.first == key && memberList[current.second].valid == 1)
		{
			count++;
			memberList[current.second].valid = 0;
		}
	}


	return count;
}