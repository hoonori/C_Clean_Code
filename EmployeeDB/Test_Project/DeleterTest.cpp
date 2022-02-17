#include "pch.h"
#include <fstream>
#include "../EmployeeDB/DataStructure.h"
#include "../EmployeeDB/Deleter.h"
#include "../EmployeeDB/Printer.h"
#include "../EmployeeDB/Parser.h"



TEST(DeleteTest, BasicTest) {
	DataBase* database = new DataBase();
	ofstream ofs;

	string outFileName = "output_test.txt";
	ofs.open(outFileName);

	Printer* printer = new Printer(&ofs);
	Parser* parser = new Parser();
	Deleter deleter(database, printer, parser);

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
	
	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::none, KeyType::EmployeeNum, list[0].employeeNum), 1);
	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::none, KeyType::Name, list[1].name), 1);
	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::none, KeyType::Cl, list[2].cl), 1);
	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::none, KeyType::PhoneNum, list[3].phoneNum), 1);
	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::none, KeyType::Birthday, list[4].birthday), 1);
	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::none, KeyType::Certi, list[5].certi), 1);
	ofs.close();
	std::remove(outFileName.c_str());
}


TEST(DeleteTest, Option2Test) {
	DataBase* database = new DataBase();
	ofstream ofs;

	string outFileName = "output_test.txt";
	ofs.open(outFileName);

	Printer* printer = new Printer(&ofs);
	Parser* parser = new Parser();
	Deleter deleter(database, printer, parser);

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

	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::f, KeyType::Name,"JIHOON"),1);
	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::l, KeyType::Name, "PARK"), 1);

	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::m, KeyType::PhoneNum, "0010"), 1);
	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::l, KeyType::PhoneNum, "0003"), 1);

	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::y, KeyType::Birthday, "97"), 1);
	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::m, KeyType::Birthday, "04"), 1);
	EXPECT_EQ(deleter.Delete(OptionType::none, OptionType::d, KeyType::Birthday, "25"), 1);
	ofs.close();
	std::remove(outFileName.c_str());
}



TEST(DeleteTest, Option1Test)
{
	DataBase* database = new DataBase();

	ofstream ofs;

	string outFileName = "output_test.txt";
	ofs.open(outFileName);

	Printer* printer = new Printer(&ofs);
	Parser* parser = new Parser();
	Deleter deleter(database, printer, parser);

	Employee list[7];
	list[0] = { true, "69000000", "JIHOON KIM", "CL2", "010-0000-0000", "970319", "PRO", "JIHOON", "KIM", "0000", "0000", "97", "03", "19" };
	list[1] = { true, "69000001", "DONGWOO PARK", "CL2", "010-0000-0001", "970320", "PRO", "DONGWOO", "PARK", "0000", "0001", "97", "03", "20" };
	list[2] = { true, "70000002", "JOONGHYUN KIM", "CL2", "010-0010-0002", "970321", "PRO", "JOONGHYUN", "KIM", "0010", "0002", "97", "03", "21" };
	list[3] = { true, "70000003", "DONGIL LEE", "CL2", "010-0000-0003", "970322", "PRO", "DONGIL", "LEE", "0000", "0003", "97", "03", "22" };
	list[4] = { true, "19000004", "SEUNGJI GWAK", "CL2", "010-0000-0004", "970323", "PRO", "SEUNGJI", "GWAK", "0000", "0004", "97", "03", "23" };
	list[5] = { true, "20000005", "YOUNGDOO KIM", "CL2", "010-0000-0005", "980424", "PRO", "YOUNGDOO", "KIM", "0000", "0005", "98", "04", "24" };
	list[6] = { true, "21000006", "JUNSEOK YANG", "CL2", "010-0000-0006", "990525", "EX", "JUNSEOK", "YANG", "0000", "0006", "99", "05", "25" };

	for (int i = 0; i < 7; i++)
	{
		database->CreateRecord(list[i]);
	}

	EXPECT_EQ(7,deleter.Delete(OptionType::p, OptionType::none, KeyType::Cl, "CL2"));
	EXPECT_EQ(0,deleter.Delete(OptionType::p, OptionType::none, KeyType::Cl, "CL2"));

	string expected1 = "DEL,69000000,JIHOON KIM,CL2,010-0000-0000,970319,PRO";
	string expected2 = "DEL,69000001,DONGWOO PARK,CL2,010-0000-0001,970320,PRO";
	string expected3 = "DEL,70000002,JOONGHYUN KIM,CL2,010-0010-0002,970321,PRO";
	string expected4 = "DEL,70000003,DONGIL LEE,CL2,010-0000-0003,970322,PRO";
	string expected5 = "DEL,19000004,SEUNGJI GWAK,CL2,010-0000-0004,970323,PRO";
	string expected6 = "DEL,NONE";
	ofs.close();

	ifstream ifs;

	ifs.open(outFileName);

	string line;

	string res1;
	string res2;
	string res3;
	string res4;
	string res5;
	string res6;


	int index = 0;
	while (getline(ifs, line)) {
		if (index == 0) {
			res1 = line;
		}
		else if (index == 1) {
			res2 = line;
		}
		else if (index == 2) {
			res3 = line;
		}
		else if (index == 3) {
			res4 = line;
		}
		else if (index == 4) {
			res5 = line;
		}
		else if (index == 5) {
			res6 = line;
		}

		index++;
	}

	EXPECT_EQ(0, res1.compare(expected1));
	EXPECT_EQ(0, res2.compare(expected2));
	EXPECT_EQ(0, res3.compare(expected3));
	EXPECT_EQ(0, res4.compare(expected4));
	EXPECT_EQ(0, res5.compare(expected5));
	EXPECT_EQ(0, res6.compare(expected6));
	EXPECT_EQ(res6, expected6);


	ifs.close();
	std::remove(outFileName.c_str());
}
