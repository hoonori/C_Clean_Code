#include "searchFunc.h"
#include "data_structure.h"

int searchFunc::Search(string type, string data){

	int count = 0;
	multimap<string, int> *pMap;

	if (!type.compare("employeeNum"))
		pMap = &employeeNum_map;
	else if (!type.compare("name"))
		pMap = &name_map;
	else if (!type.compare("cl"))
		pMap = &cl_map;
	else if (!type.compare("phoneNum"))
		pMap = &phoneNum_map;
	else if (!type.compare("birthday"))
		pMap = &birthday_map;
	else 
		pMap = &certi_map;


	if (pMap->count(data) == 0) {
		printf("SCH,NONE\n");
	}
	else{
		printf("SCH,%d\n", (int)pMap->count(data));
	}
	return pMap->count(data);

}
