#include "pch.h"

#include<cstdio>
#include <fstream>
#include <string>
#include "../EmployeeDB/Printer.h"

using namespace testing;

class PrinterTest : public testing::Test
{
protected:
	void SetUp(void) override {

		ofs.open(outFileName);
		printer = new Printer(&ofs);

	}

	void TearDown(void) override {
		ofs.close();
		ifs.close();
		std::remove(outFileName.c_str());
		delete printer;
	}

	ofstream ofs;
	ifstream ifs;
	Printer* printer;
	string outFileName = "output_test.txt";
};
TEST_F(PrinterTest, PrintTest) {
	
	string expected1 = "MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO";
	string expected2 = "SCH,NONE";
	string expected3 = "DEL,1";

	printer->PrintRecord("MOD", "17112609", "FB NTAWR", "CL4", "010-5645-6122", "19861203", "PRO");
	printer->PrintNone("SCH");
	printer->PrintCount("DEL", 1);

	ifs.open(outFileName);

	string line;

	string res1;
	string res2;
	string res3;

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

		index++;
	}
	
	EXPECT_EQ(0, res1.compare(expected1));
	EXPECT_EQ(0, res2.compare(expected2));
	EXPECT_EQ(0, res3.compare(expected3));
}