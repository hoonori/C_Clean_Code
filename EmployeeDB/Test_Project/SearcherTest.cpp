#include "pch.h"
#include "../EmployeeDB/Searcher.h"
#include "../EmployeeDB/DataBase.h"
#include "../EmployeeDB/Printer.h"

#include "MockPrinter.h"

using namespace testing;

class SearcherTest : public testing::Test
{
protected:
	void SetUp(void) override {
		database = new DataBase();
		mockPrinter = new MockPrinter();
		searcher = new Searcher(database, mockPrinter);

		list[0] = { true, "15123099", "JUNSEOK A", "CL4", "010-0006-0006", "19970325", "EX", "JUNSEOK", "A", "0006", "0006", "1997", "03", "25" };
		list[1] = { true, "69000000", "JUNSEOK A", "CL4", "010-0006-0006", "19970325", "EX", "JUNSEOK", "A", "0006", "0006", "1997", "03", "25" };
		list[2] = { true, "69000001", "JUNSEOK C", "CL4", "010-0002-0002", "19970427", "EX", "JUNSEOK", "C", "0002", "0002", "1997", "04", "27" };
		list[3] = { true, "88114052", "JUNSEOK D", "CL4", "010-0006-0006", "19970527", "EX", "JUNSEOK", "D", "0006", "0006", "1997", "05", "27" };
		list[4] = { true, "99999999", "JUNSEOK E", "CL4", "010-0006-0006", "19970626", "EX", "JUNSEOK", "E", "0006", "0006", "1997", "06", "26" };
		list[5] = { true, "21999998", "JUNSEOK F", "CL4", "010-0003-0003", "19970727", "EX", "JUNSEOK", "F", "0003", "0003", "1997", "07", "27" };
		list[6] = { true, "21999999", "JUNSEOK G", "CL4", "010-0002-0004", "19970825", "EX", "JUNSEOK", "G", "0002", "0004", "1997", "08", "25" };
		list[7] = { true, "00000000", "JUNSEOK G", "CL4", "010-0007-0007", "19970925", "EX", "JUNSEOK", "G", "0007", "0007", "1997", "09", "25" };

		for (int i = 0; i < 8; i++)
		{
			database->CreateRecord(list[i]);
		}
	}

	void TearDown(void) override {
		delete database;
		delete mockPrinter;
		delete searcher;
	}

	DataBase* database;
	Searcher* searcher;
	MockPrinter* mockPrinter;

	Employee list[8];

};
TEST_F(SearcherTest, BasicTest) {

	EXPECT_CALL(*mockPrinter, PrintRecord("SCH", _, _, _, _, _, _)).Times(0);
	EXPECT_CALL(*mockPrinter, PrintNone("SCH")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("SCH", 8)).Times(1);

	searcher->Search(KeyType::Cl, "CL4", OptionType::none, OptionType::none);
}

TEST_F(SearcherTest, BasicTest2) {

	EXPECT_CALL(*mockPrinter, PrintRecord("SCH", _, _, _, _, _, _)).Times(0);
	EXPECT_CALL(*mockPrinter, PrintNone("SCH")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("SCH", 2)).Times(1);

	searcher->Search(KeyType::Name, "JUNSEOK G", OptionType::none, OptionType::none);
}

TEST_F(SearcherTest, BasicTest3) {

	EXPECT_CALL(*mockPrinter, PrintRecord("SCH", _, _, _, _, _, _)).Times(0);
	EXPECT_CALL(*mockPrinter, PrintNone("SCH")).Times(1);
	EXPECT_CALL(*mockPrinter, PrintCount("SCH", _)).Times(0);

	searcher->Search(KeyType::Cl, "CL3", OptionType::none, OptionType::none);
}


TEST_F(SearcherTest, Option1Test)
{
	EXPECT_CALL(*mockPrinter, PrintRecord("SCH", _, _, _, _, _, _)).Times(5);
	EXPECT_CALL(*mockPrinter, PrintNone("SCH")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("SCH", _)).Times(0);

	searcher->Search(KeyType::Cl, "CL4", OptionType::p, OptionType::none);
}

TEST_F(SearcherTest, Option1Test2)
{
	EXPECT_CALL(*mockPrinter, PrintRecord("SCH", _, _, _, _, _, _)).Times(4);
	EXPECT_CALL(*mockPrinter, PrintNone("SCH")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("SCH", _)).Times(0);

	searcher->Search(KeyType::PhoneNum, "010-0006-0006", OptionType::p, OptionType::none);
}

TEST_F(SearcherTest, Option2Test) {

	EXPECT_CALL(*mockPrinter, PrintRecord("SCH", _, _, _, _, _, _)).Times(5);
	EXPECT_CALL(*mockPrinter, PrintNone("SCH")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("SCH", _)).Times(0);

	searcher->Search(KeyType::Name, "JUNSEOK", OptionType::p, OptionType::f);
}

TEST_F(SearcherTest, Option2Test2) {

	EXPECT_CALL(*mockPrinter, PrintRecord("SCH", _, _, _, _, _, _)).Times(2);
	EXPECT_CALL(*mockPrinter, PrintNone("SCH")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("SCH", _)).Times(0);

	searcher->Search(KeyType::Name, "G", OptionType::p, OptionType::l);
}

TEST_F(SearcherTest, Option2Test3) {

	EXPECT_CALL(*mockPrinter, PrintRecord("SCH", _, _, _, _, _, _)).Times(4);
	EXPECT_CALL(*mockPrinter, PrintNone("SCH")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("SCH", _)).Times(0);

	searcher->Search(KeyType::PhoneNum, "0006", OptionType::p, OptionType::m);
}

TEST_F(SearcherTest, Option2Test4) {

	EXPECT_CALL(*mockPrinter, PrintRecord("SCH", _, _, _, _, _, _)).Times(1);
	EXPECT_CALL(*mockPrinter, PrintNone("SCH")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("SCH", _)).Times(0);

	searcher->Search(KeyType::PhoneNum, "0003", OptionType::p, OptionType::l);
}

TEST_F(SearcherTest, Option2Test5) {

	EXPECT_CALL(*mockPrinter, PrintRecord("SCH", _, _, _, _, _, _)).Times(4);
	EXPECT_CALL(*mockPrinter, PrintNone("SCH")).Times(0);
	EXPECT_CALL(*mockPrinter, PrintCount("SCH", _)).Times(0);

	searcher->Search(KeyType::Birthday, "25", OptionType::p, OptionType::d);
}