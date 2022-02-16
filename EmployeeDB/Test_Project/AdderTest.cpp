#include "pch.h"
#include "../EmployeeDB/Adder.h"
#include "../EmployeeDB/DataBase.h"

TEST(AdderTest, AddTest) {
	DataBase* db = new DataBase();
	Adder* adder = new Adder(db);

	string employeeNum = "15123099";
	string name = "VXIHXOTH JHOP";;
	string cl = "CL3";
	string phoneNum = "010-3112-2609";
	string birthday = "19771211";
	string certi = "ADV";

	adder->Add(employeeNum, name, cl, phoneNum, birthday, certi);

	Employee res = db->ReadRecord(0);
	EXPECT_EQ(true, res.valid);
	EXPECT_EQ(0, res.employeeNum.compare("15123099"));

	EXPECT_EQ(0, res.name.compare("VXIHXOTH JHOP"));
	EXPECT_EQ(0, res.firstName.compare("VXIHXOTH"));
	EXPECT_EQ(0, res.lastName.compare("JHOP"));
	EXPECT_EQ(0, res.cl.compare("CL3"));

	EXPECT_EQ(0, res.phoneNum.compare("010-3112-2609"));
	EXPECT_EQ(0, res.middlePhoneNum.compare("3112"));
	EXPECT_EQ(0, res.lastPhoneNum.compare("2609"));

	EXPECT_EQ(0, res.birthday.compare("19771211"));
	EXPECT_EQ(0, res.yearBirth.compare("1977"));
	EXPECT_EQ(0, res.monthBirth.compare("12"));
	EXPECT_EQ(0, res.dayBirth.compare("11"));

	EXPECT_EQ(0, res.certi.compare("ADV"));
}