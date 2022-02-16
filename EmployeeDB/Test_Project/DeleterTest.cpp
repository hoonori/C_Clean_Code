#include "pch.h"
#include "../EmployeeDB/DataStructure.h"
#include "../EmployeeDB/Deleter.h"



TEST(DeleteTest, BasicTest) {
	DataBase* database = new DataBase();
	Deleter deleter(database);

	Employee list[7];
	list[0] = {true, "00000000", "JIHOON KIM", "CL2", "010-0000-0000", "970319", "PRO"};
	list[1] = {true, "00000001", "DONGWOO KIM", "CL2", "010-0000-0001", "970320", "PRO"};
	list[2] = {true, "00000002", "JOONGHYUN KIM", "CL2", "010-0000-0002", "970321", "PRO"};
	list[3] = {true, "00000003", "DONGIL LEE", "CL3", "010-0000-0003", "970322", "PRO"};
	list[4] = {true, "00000004", "SEUNGJI GWAK", "CL4", "010-0000-0004", "970323", "PRO"};
	list[5] = {true, "00000005", "YOUNGDOO KIM", "CL3", "010-0000-0005", "970324", "PRO"};
	list[6] = {true, "00000006", "JUNSEOK YANG", "CL4", "010-0000-0006", "970325", "EX"};

	for (int i = 0; i < 7; i++)
	{
		database->CreateRecord(list[i]);
	}
	
	EXPECT_EQ(deleter.Delete(0,0,KeyType::EmployeeNum, list[0].employeeNum), 1);
	EXPECT_EQ(deleter.Delete(0,0, KeyType::Name, list[1].name), 1);
	EXPECT_EQ(deleter.Delete(0,0, KeyType::Cl, list[2].cl), 1);
	EXPECT_EQ(deleter.Delete(0,0, KeyType::PhoneNum, list[3].phoneNum), 1);
	EXPECT_EQ(deleter.Delete(0,0, KeyType::Birthday, list[4].birthday), 1);
	EXPECT_EQ(deleter.Delete(0,0, KeyType::Certi, list[5].certi), 1);
	
}