#include "pch.h"
#include "../EmployeeDB/Parser.cpp"
#include "../EmployeeDB/Deleter.cpp"
#include "../EmployeeDB/data_structure.h"

/*
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

*/

TEST(TestCaseName, ParseTest) {
	Parser parser;

	string str = "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV";
	int res = parser.Parse(str);
	EXPECT_EQ(res, 0);
}

TEST(TestCaseName, DelTest) {
	Deleter del;

	Employee list[7];
	list[0] = {1, "00000000", "JIHOON KIM", "CL2", "010-0000-0000", "970319", "PRO"};
	list[1] = {1, "00000001", "DONGWOO KIM", "CL2", "010-0000-0001", "970320", "PRO"};
	list[2] = {1, "00000002", "JOONGHYUN KIM", "CL2", "010-0000-0002", "970321", "PRO"};
	list[3] = {1, "00000003", "DONGIL LEE", "CL3", "010-0000-0003", "970322", "PRO"};
	list[4] = {1, "00000004", "SEUNGJI GWAK", "CL4", "010-0000-0004", "970323", "PRO"};
	list[5] = {1, "00000005", "YOUNGDOO KIM", "CL3", "010-0000-0005", "970324", "PRO"};
	list[6] = {1, "00000006", "JUNSEOK YANG", "CL4", "010-0000-0006", "970325", "EX"};

	for (int i = 0; i < 7; i++)
	{
		memberList[i] = list[i];
		employeeNum_map.insert({ list[i].employeeNum, i });
		name_map.insert({list[i].name, i});
		cl_map.insert({ list[i].cl, i });
		phoneNum_map.insert({list[i].phoneNum, i});
		birthday_map.insert({ list[i].birthday, i });
		certi_map.insert({list[i].certi, i});
	}

	EXPECT_EQ(del.Delete(0,list[0].employeeNum), 1);
	EXPECT_EQ(del.Delete(1, list[1].name), 1);
	EXPECT_EQ(del.Delete(2, list[2].cl), 1);
	EXPECT_EQ(del.Delete(3, list[3].phoneNum), 1);
	EXPECT_EQ(del.Delete(4, list[4].birthday), 1);
	EXPECT_EQ(del.Delete(5, list[5].certi), 1);
}