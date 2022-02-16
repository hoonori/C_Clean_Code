#include "pch.h"
#include "../EmployeeDB/Adder.h"
#include "../EmployeeDB/Modifier.h"
#include "../EmployeeDB/DataBase.h"


TEST(ModifierTest, ModTest) {
	DataBase* db = new DataBase();
	Adder* adder = new Adder(db);
	Modifier* modifier = new Modifier(db);


	string employeeNum = "15123099";
	string name = "VXIHXOTH JHOP";;
	string cl = "CL3";
	string phoneNum = "010-3112-2609";
	string birthday = "19771211";
	string certi = "ADV";

	adder->Add(employeeNum, name, cl, phoneNum, birthday, certi);

	employeeNum = "25123099";
	name = "VXIHXOTH HHOP";;
	cl = "CL3";
	phoneNum = "010 - 1234 - 2609";
	birthday = "19771212";
	certi = "PRO";

	adder->Add(employeeNum, name, cl, phoneNum, birthday, certi);

	modifier->Modify(KeyType::Cl, "CL3", KeyType::Certi, "EX", NULL, NULL, NULL);

	EXPECT_EQ("EX", db->ReadRecord(0).certi);
	EXPECT_EQ("EX", db->ReadRecord(1).certi);

	modifier->Modify(KeyType::Name, "VXIHXOTH HHOP", KeyType::Birthday, "20000101", NULL, NULL, NULL);
	EXPECT_EQ("20000101", db->ReadRecord(1).birthday);
	EXPECT_NE("20000101", db->ReadRecord(0).birthday);

	modifier->Modify(KeyType::Name, "HHOP", KeyType::Birthday, "21001101", NULL, '-l', NULL);
	EXPECT_EQ("21001101", db->ReadRecord(1).birthday);

	modifier->Modify(KeyType::Name, "VXIHXOTH", KeyType::Certi, "ADV", NULL, '-f', NULL);
	EXPECT_EQ("ADV", db->ReadRecord(0).certi);
	EXPECT_EQ("ADV", db->ReadRecord(1).certi);


}