#include "data_structure.h"

bool MOD(datatype cond_type, string cond_data, datatype mod_type, string mod_data) {

	multimap<string, int>* ptrCondMap;
	multimap<string, int>* ptrModMap;


	if (cond_type == EMPLOYEENUM)
		ptrCondMap = &employeeNum_map;
	else if (cond_type == NAME)
		ptrCondMap = &name_map;
	else if (cond_type == CL)
		ptrCondMap = &cl_map;
	else if (cond_type == PHONENUM)
		ptrCondMap = &phoneNum_map;
	else if (cond_type == BIRTHDAY)
		ptrCondMap = &birthday_map;
	else
		ptrCondMap = &certi_map;

	if (mod_type == EMPLOYEENUM)
		ptrModMap = &employeeNum_map;
	else if (mod_type == NAME)
		ptrModMap = &name_map;
	else if (mod_type == CL)
		ptrModMap = &cl_map;
	else if (mod_type == PHONENUM)
		ptrModMap = &phoneNum_map;
	else if (mod_type == BIRTHDAY)
		ptrModMap = &birthday_map;
	else
		ptrModMap = &certi_map;


	if (ptrCondMap->count(cond_data) == 0) {
		cout << "There is no data matching the condition" << endl;
		return false;
	}

	for (auto cond = ptrCondMap->lower_bound(cond_data); cond != ptrCondMap->upper_bound(cond_data); cond++) {
		int index = cond->second;

		if (index >= MAX_MEMBER || index < 0) {
			cout << "Invalid index value" << endl;
			return false;
		}

		// 주 배열 변경
		if (mod_type == EMPLOYEENUM)
			memberList[index].employeeNum = mod_data;
		else if (mod_type == NAME)
			memberList[index].name = mod_data;
		else if (mod_type == CL)
			memberList[index].cl = mod_data;
		else if (mod_type == PHONENUM)
			memberList[index].phoneNum = mod_data;
		else if (mod_type == BIRTHDAY)
			memberList[index].birthday = mod_data;
		else if (mod_type == CERTI)
			memberList[index].certi = mod_data;

		//요소 맵에서 기존 데이터 삭제
		for (auto mod = ptrModMap->begin(); mod != ptrModMap->end(); mod++) {
			if (mod->second == index)
				ptrModMap->erase(mod);
		}

		//요소 맵에서 새 데이터 추가
		ptrModMap->insert(pair<string, int>(mod_data, index));
	}

	return true;

}