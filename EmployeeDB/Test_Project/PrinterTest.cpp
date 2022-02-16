#include "pch.h"

#include<cstdio>
#include <fstream>
#include <string>
#include "../EmployeeDB/Printer.h"

TEST(PrinterTest, PrintTest) {
	
	ofstream ofs;

	string outFileName = "output_test.txt";
	ofs.open(outFileName);

	string expected1 = "MOD, 17112609, FB NTAWR, CL4, 010 - 5645 - 6122, 19861203, PRO";
	string expected2 = "SCH, NONE";
	string expected3 = "DEL, 1";

	Printer printer(&ofs);

	printer.PrintRecord("MOD", "17112609", "FB NTAWR", "CL4", "010 - 5645 - 6122", "19861203", "PRO");
	printer.PrintNone("SCH");
	printer.PrintCount("DEL", 1);

	EXPECT_TRUE(false);
}