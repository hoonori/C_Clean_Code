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

TEST(DeleteTest, Option2Test) {
	DataBase* database = new DataBase();
	Deleter deleter(database);

	Employee list[7];
	list[0] = { true, "00000000", "JIHOON KIM", "CL2", "010-0000-0000", "970319", "PRO", "JIHOON", "KIM", "0000", "0000", "97", "03", "19"};
	list[1] = { true, "00000001", "DONGWOO PARK", "CL2", "010-0000-0001", "970320", "PRO", "DONGWOO", "PARK", "0000", "0001", "97", "03", "20" };
	list[2] = { true, "00000002", "JOONGHYUN KIM", "CL2", "010-0010-0002", "970321", "PRO", "JOONGHYUN", "KIM", "0010", "0002", "97", "03", "21" };
	list[3] = { true, "00000003", "DONGIL LEE", "CL3", "010-0000-0003", "970322", "PRO", "DONGIL", "LEE", "0000", "0003", "97", "03", "22" };
	list[4] = { true, "00000004", "SEUNGJI GWAK", "CL4", "010-0000-0004", "970323", "PRO", "SEUNGJI", "GWAK", "0000", "0004", "97", "03", "23" };
	list[5] = { true, "00000005", "YOUNGDOO KIM", "CL3", "010-0000-0005", "980424", "PRO", "YOUNGDOO", "KIM", "0000", "0005", "98", "04", "24" };
	list[6] = { true, "00000006", "JUNSEOK YANG", "CL4", "010-0000-0006", "990525", "EX", "JUNSEOK", "YANG", "0000", "0006", "99", "05", "25" };

	for (int i = 0; i < 7; i++)
	{
		database->CreateRecord(list[i]);
	}

	EXPECT_EQ(deleter.Delete(0, 'f', KeyType::Name,"JIHOON"),1);
	EXPECT_EQ(deleter.Delete(0, 'l', KeyType::Name, "PARK"), 1);

	EXPECT_EQ(deleter.Delete(0, 'm', KeyType::PhoneNum, "0010"), 1);
	EXPECT_EQ(deleter.Delete(0, 'l', KeyType::PhoneNum, "0003"), 1);

	EXPECT_EQ(deleter.Delete(0, 'y', KeyType::Birthday, "97"), 1);
	EXPECT_EQ(deleter.Delete(0, 'm', KeyType::Birthday, "04"), 1);
	EXPECT_EQ(deleter.Delete(0, 'd', KeyType::Birthday, "25"), 1);
}