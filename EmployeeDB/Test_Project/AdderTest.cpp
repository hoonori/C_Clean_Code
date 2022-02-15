#include "pch.h"
#include "../EmployeeDB/Adder.cpp"
#include "../EmployeeDB/Adder.h"
#include "../EmployeeDB/DataBase.cpp"
#include "../EmployeeDB/DataBase.h"

TEST(AdderTest, AddTest) {
	DataBase* db = new DataBase();
	Adder* adder = new Adder(db);

	string employeeNum = "15123099";
	string name = "VXIHXOTH JHOP";;
	string cl = "CL3";
	string phoneNum = "010 - 3112 - 2609";
	string birthday = "19771211";
	string certi = "ADV";

	adder->Add(employeeNum, name, cl, phoneNum, birthday, certi);

	EXPECT_TRUE(false);
}