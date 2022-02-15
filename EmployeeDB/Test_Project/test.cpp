#include "pch.h"
#include "../EmployeeDB/Parser.cpp"
#include "../EmployeeDB/searchFunc.cpp"
#include"../EmployeeDB/data_structure.h"

/*
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

*/

//TEST(TestCaseName, ParseTest) {
//	Parser parser;
//
//	string str = "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV";
//	int res = parser.Parse(str);
//	EXPECT_EQ(res, 0);
//}

TEST(TestCaseName, SearchTest) {

	string employeeNum = "15123099";
	string name = "VXIHXOTH JHOP";;
	string cl = "CL3";
	string phoneNum = "010 - 3112 - 2609";
	string birthday = "19771211";
	string certi = "ADV";

	Employee employee;
	searchFunc search;

	employee.employeeNum = employeeNum;
	employee.name = name;
	employee.cl = cl;
	employee.phoneNum = phoneNum;
	employee.birthday = birthday;
	employee.certi = certi;
	employee.valid = 1;

	int maxNum = 5;
	for (int cnt = 1; cnt <= maxNum; cnt++) {
		memberList[cnt] = employee;

		employeeNum_map.insert({ employeeNum, cnt });
		name_map.insert({ name, cnt });
		cl_map.insert({ cl, cnt });
		phoneNum_map.insert({ phoneNum, cnt });
		birthday_map.insert({ birthday, cnt });
		certi_map.insert({ certi, cnt });
	}
	
	
	string einfo = "employeeNum";
	EXPECT_EQ(search.Search(einfo, employeeNum), maxNum);

	einfo = "name";
	EXPECT_EQ(search.Search(einfo, name), maxNum);

	einfo = "cl";
	EXPECT_EQ(search.Search(einfo, cl), maxNum);

	einfo = "phoneNum";
	EXPECT_EQ(search.Search(einfo, phoneNum), maxNum);

	einfo = "birthday";
	EXPECT_EQ(search.Search(einfo, birthday), maxNum);

	einfo = "certi";
	EXPECT_EQ(search.Search(einfo, certi), maxNum);

	einfo = "phoneNum";
	EXPECT_EQ(search.Search(einfo, employeeNum), 0);

	einfo = "birthday";
	EXPECT_EQ(search.Search(einfo, employeeNum), 0);

	einfo = "certi";
	EXPECT_EQ(search.Search(einfo, employeeNum), 0);

}