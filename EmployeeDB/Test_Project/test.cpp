#include "pch.h"
#include "../EmployeeDB/Parser.cpp"
/*
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

*/

TEST(TestCaseName, ParseTest) {
	Parser parser;

	string str = "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV";
	int res = parser.Parse(str);
	EXPECT_EQ(res, 0);
}

