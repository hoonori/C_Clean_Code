#include "pch.h"
#include "../EmployeeDB/Searcher.h"
#include "../EmployeeDB/DataBase.h"
#include "../EmployeeDB/Printer.h"
#include "../EmployeeDB/Adder.h"

TEST(SearcherTest, TestName) {

	ofstream ofs2;
	ofs2.open("test.txt");

	DataBase* database = new DataBase();
	Printer* printer = new Printer(&ofs2);
	Searcher* searcher = new Searcher(database, printer);
	Adder* adder = new Adder(database);

	adder->Add("15123099", "JUNSEOK A", "CL4", "010-0006-0006", "19970325", "EX");
	adder->Add("69000000", "JUNSEOK A", "CL4", "010-0006-0006", "19970325", "EX");
	adder->Add("69000001", "JUNSEOK C", "CL4", "010-0002-0002", "19970427", "EX");
	adder->Add("88114052", "JUNSEOK D", "CL4", "010-0006-0006", "19970527", "EX");
	adder->Add("99999999", "JUNSEOK E", "CL4", "010-0006-0006", "19970626", "EX");
	adder->Add("21999998", "JUNSEOK F", "CL4", "010-0003-0003", "19970727", "EX");
	adder->Add("21999999", "JUNSEOK G", "CL4", "010-0002-0004", "19970825", "EX");
	adder->Add("00000000", "JUNSEOK G", "CL4", "010-0007-0007", "19970925", "EX");

	bool istrue = searcher->Search(KeyType::LastPhoneNum, "25", OptionType::p, OptionType::d);
	EXPECT_EQ(istrue, true);

}