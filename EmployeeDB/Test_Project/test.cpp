#include "pch.h"
#include "../EmployeeDB/Parser.cpp"
#include "../EmployeeDB/Adder.cpp"
#include"../EmployeeDB/data_structure.h"
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

TEST(TestCaseName, AddTest) {
	Adder adder;

	string employeeNum = "15123099";
	string name = "VXIHXOTH JHOP";;
	string cl = "CL3";
	string phoneNum = "010 - 3112 - 2609";
	string birthday = "19771211";
	string certi = "ADV";

	adder.Add(employeeNum, name, cl, phoneNum, birthday, certi);

	EXPECT_TRUE(false);
}