#include "pch.h"
#include "../EmployeeDB/Adder.h"
#include "../EmployeeDB/Modifier.h"
#include "../EmployeeDB/DataBase.h"
#include "../EmployeeDB/IPrinter.h"

#include "MockPrinter.h"

using namespace testing;

class ModifierTest : public testing::Test
{
protected:
	void SetUp(void) override {
		database = new DataBase();
		mockPrinter = new MockPrinter();
		modifier = new Modifier(database, mockPrinter);

		list[0] = { true, "00000000", "JIHOON KIM", "CL2", "010-0000-0000", "19970319", "PRO", "JIHOON", "KIM", "0000", "0000", "1997", "03", "19" };
		list[1] = { true, "00000001", "DONGWOO PARK", "CL2", "010-0000-0001", "19970320", "PRO", "DONGWOO", "PARK", "0000", "0001", "1997", "03", "20" };
		list[2] = { true, "00000002", "JOONGHYUN KIM", "CL2", "010-0010-0002", "19970321", "PRO", "JOONGHYUN", "KIM", "0010", "0002", "1997", "03", "21" };
		list[3] = { true, "00000003", "DONGIL LEE", "CL3", "010-0000-0003", "19970322", "PRO", "DONGIL", "LEE", "0000", "0003", "97", "1903", "22" };
		list[4] = { true, "00000004", "SEUNGJI GWAK", "CL4", "010-0000-0004", "19970323", "PRO", "SEUNGJI", "GWAK", "0000", "0004", "1997", "03", "23" };
		list[5] = { true, "00000005", "YOUNGDOO KIM", "CL3", "010-0000-0005", "19980424", "PRO", "YOUNGDOO", "KIM", "0000", "0005", "1998", "04", "24" };
		list[6] = { true, "00000006", "JUNSEOK YANG", "CL4", "010-0000-0006", "19990525", "EX", "JUNSEOK", "YANG", "0000", "0006", "1999", "05", "25" };

		for (int i = 0; i < 7; i++)
		{
			database->CreateRecord(list[i]);
		}
	}

	void TearDown(void) override {
		delete database;
		delete mockPrinter;
		delete modifier;
	}

	DataBase* database;
	Modifier* modifier;
	MockPrinter* mockPrinter;

	Employee list[7];

};
TEST_F(ModifierTest, BasicTest) {
	EXPECT_CALL(*mockPrinter, PrintRecord("MOD", _, _, _, _, _, _)).Times(0);
	EXPECT_CALL(*mockPrinter, PrintNone("MOD")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("MOD", 2)).Times(1);

	modifier->Modify(KeyType::Cl, "CL3", KeyType::Certi, "EX", OptionType::none, OptionType::none);

	string expected1 = database->ReadRecord(3).certi;
	string expected2 = database->ReadRecord(5).certi;

	EXPECT_EQ(0, expected1.compare("EX"));
	EXPECT_EQ(0, expected2.compare("EX"));
}

TEST_F(ModifierTest, Option1Test) {
	EXPECT_CALL(*mockPrinter, PrintRecord("MOD", _, _, _, _, _, _)).Times(1);
	EXPECT_CALL(*mockPrinter, PrintNone("MOD")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("MOD", _)).Times(0);

	modifier->Modify(KeyType::Certi, "EX", KeyType::Cl, "CL1", OptionType::p, OptionType::none);

	string expected1 = database->ReadRecord(6).cl;

	EXPECT_EQ(0, expected1.compare("CL1"));
}

TEST_F(ModifierTest, Option2Test) {
	EXPECT_CALL(*mockPrinter, PrintRecord("MOD", _, _, _, _, _, _)).Times(1);
	EXPECT_CALL(*mockPrinter, PrintNone("MOD")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("MOD", _)).Times(0);

	modifier->Modify(KeyType::Name, "JUNSEOK", KeyType::Cl, "CL4", OptionType::p, OptionType::f);

	string expected1 = database->ReadRecord(6).cl;

	EXPECT_EQ(0, expected1.compare("CL4"));
}
TEST_F(ModifierTest, ModifyNameTest) {
	EXPECT_CALL(*mockPrinter, PrintRecord("MOD", _, _, _, _, _, _)).Times(1);
	EXPECT_CALL(*mockPrinter, PrintNone("MOD")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("MOD", _)).Times(0);

	modifier->Modify(KeyType::Name, "JUNSEOK", KeyType::Name, "CLEAN CODE", OptionType::p, OptionType::f);

	string expected1 = database->ReadRecord(6).firstName;
	string expected2 = database->ReadRecord(6).lastName;

	EXPECT_EQ(0, expected1.compare("CLEAN"));
	EXPECT_EQ(0, expected2.compare("CODE"));
}

TEST_F(ModifierTest, ModifyPhoneNumTest) {
	EXPECT_CALL(*mockPrinter, PrintRecord("MOD", _, _, _, _, _, _)).Times(1);
	EXPECT_CALL(*mockPrinter, PrintNone("MOD")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("MOD", _)).Times(0);

	modifier->Modify(KeyType::Name, "JUNSEOK", KeyType::PhoneNum, "010-8927-0425", OptionType::p, OptionType::f);

	string expected1 = database->ReadRecord(6).middlePhoneNum;
	string expected2 = database->ReadRecord(6).lastPhoneNum;

	EXPECT_EQ(0, expected1.compare("8927"));
	EXPECT_EQ(0, expected2.compare("0425"));
}
TEST_F(ModifierTest, ModifyBirthdayTest) {
	EXPECT_CALL(*mockPrinter, PrintRecord("MOD", _, _, _, _, _, _)).Times(1);
	EXPECT_CALL(*mockPrinter, PrintNone("MOD")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("MOD", _)).Times(0);

	modifier->Modify(KeyType::Name, "JUNSEOK", KeyType::Birthday, "19930317", OptionType::p, OptionType::f);

	string expected1 = database->ReadRecord(6).yearBirth;
	string expected2 = database->ReadRecord(6).monthBirth;
	string expected3 = database->ReadRecord(6).dayBirth;


	EXPECT_EQ(0, expected1.compare("1993"));
	EXPECT_EQ(0, expected2.compare("03"));
	EXPECT_EQ(0, expected3.compare("17"));
}
