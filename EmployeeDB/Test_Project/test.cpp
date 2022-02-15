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

	Employee employee = memberList[currentIndex - 1];

	EXPECT_EQ(1, employee.valid);
	EXPECT_EQ(0, employeeNum.compare(employee.employeeNum));
	EXPECT_EQ(0, name.compare(employee.name));
	EXPECT_EQ(0, cl.compare(employee.cl));
	EXPECT_EQ(0, phoneNum.compare(employee.phoneNum));
	EXPECT_EQ(0, birthday.compare(employee.birthday));
	EXPECT_EQ(0, certi.compare(employee.certi));

	auto iter = employeeNum_map.find(employeeNum);
	EXPECT_TRUE(iter != employeeNum_map.end());

	iter = name_map.find(name);
	EXPECT_TRUE(iter != name_map.end());

	iter = cl_map.find(cl);
	EXPECT_TRUE(iter != cl_map.end());

	iter = phoneNum_map.find(phoneNum);
	EXPECT_TRUE(iter != phoneNum_map.end());

	iter = birthday_map.find(birthday);
	EXPECT_TRUE(iter != birthday_map.end());

	iter = certi_map.find(certi);
	EXPECT_TRUE(iter != certi_map.end());
}