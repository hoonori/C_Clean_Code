#include "pch.h"
#include <fstream>
#include "../EmployeeDB/DataStructure.h"
#include "../EmployeeDB/Deleter.h"
#include "../EmployeeDB/Printer.h"
#include "../EmployeeDB/Parser.h"

#include "MockPrinter.h"

using namespace testing;

class DeleterTest : public testing::Test
{
protected:
	void SetUp(void) override {
		database = new DataBase();
		mockPrinter = new MockPrinter();
		deleter = new Deleter(database, mockPrinter);

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
		delete deleter;
	}

	DataBase* database;
	Deleter* deleter;
	MockPrinter* mockPrinter;

	Employee list[7];

};
TEST_F(DeleterTest, BasicTest) {
	
	EXPECT_CALL(*mockPrinter, PrintRecord("DEL", _, _, _, _, _, _)).Times(0);
	EXPECT_CALL(*mockPrinter, PrintNone("DEL")).Times(1);
	EXPECT_CALL(*mockPrinter, PrintCount("DEL", _)).Times(6);

	int res0 = deleter->Delete(OptionType::none, OptionType::none, KeyType::EmployeeNum, "99999999");
	EXPECT_EQ(res0, 0);

	int res1 = deleter->Delete(OptionType::none, OptionType::none, KeyType::EmployeeNum, list[0].employeeNum);
	EXPECT_EQ(res1, 1);

	int res2 = deleter->Delete(OptionType::none, OptionType::none, KeyType::Name, list[1].name);
	EXPECT_EQ(res2, 1);

	int res3 = deleter->Delete(OptionType::none, OptionType::none, KeyType::Cl, list[2].cl);
	EXPECT_EQ(res3, 1);

	int res4 = deleter->Delete(OptionType::none, OptionType::none, KeyType::PhoneNum, list[3].phoneNum);
	EXPECT_EQ(res4, 1);

	int res5 = deleter->Delete(OptionType::none, OptionType::none, KeyType::Birthday, list[4].birthday);
	EXPECT_EQ(res5, 1);

	int res6 = deleter->Delete(OptionType::none, OptionType::none, KeyType::Certi, list[5].certi);
	EXPECT_EQ(res6, 1);

}


TEST_F(DeleterTest, Option1Test)
{
	EXPECT_CALL(*mockPrinter, PrintRecord("DEL", _, _, _, _, _, _)).Times(7);
	EXPECT_CALL(*mockPrinter, PrintNone("DEL")).Times(1);
	EXPECT_CALL(*mockPrinter, PrintCount("DEL", _)).Times(0);

	int res0 = deleter->Delete(OptionType::p, OptionType::none, KeyType::Cl, "CL2");
	EXPECT_EQ(res0, 3);
	
	int res1 = deleter->Delete(OptionType::p, OptionType::none, KeyType::Certi, "PRO");
	EXPECT_EQ(res1, 3);

	int res2 = deleter->Delete(OptionType::p, OptionType::none, KeyType::Cl, "CL4");
	EXPECT_EQ(res2, 1);

	int res3 = deleter->Delete(OptionType::p, OptionType::none, KeyType::Cl, "CL3");
	EXPECT_EQ(res3, 0);

}
TEST_F(DeleterTest, Option2Test) {


	EXPECT_CALL(*mockPrinter, PrintRecord("DEL", _, _, _, _, _, _)).Times(0);
	EXPECT_CALL(*mockPrinter, PrintNone("DEL")).Times(1);
	EXPECT_CALL(*mockPrinter, PrintCount("DEL", _)).Times(7);

	int res0 = deleter->Delete(OptionType::none, OptionType::f, KeyType::Name, "JIHOON");
	EXPECT_EQ(res0, 1);

	int res1 = deleter->Delete(OptionType::none, OptionType::f, KeyType::Name, "JIHOON");
	EXPECT_EQ(res1, 0);

	int res2 = deleter->Delete(OptionType::none, OptionType::l, KeyType::Name, "PARK");
	EXPECT_EQ(res2, 1);

	int res3 = deleter->Delete(OptionType::none, OptionType::m, KeyType::PhoneNum, "0010");
	EXPECT_EQ(res3, 1);

	int res4 = deleter->Delete(OptionType::none, OptionType::l, KeyType::PhoneNum, "0003");
	EXPECT_EQ(res4, 1);

	int res5 = deleter->Delete(OptionType::none, OptionType::y, KeyType::Birthday, "1997");
	EXPECT_EQ(res5, 1);

	int res6 = deleter->Delete(OptionType::none, OptionType::m, KeyType::Birthday, "04");
	EXPECT_EQ(res6, 1);

	int res7 = deleter->Delete(OptionType::none, OptionType::d, KeyType::Birthday, "25");
	EXPECT_EQ(res7, 1);

}

