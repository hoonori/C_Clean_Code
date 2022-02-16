#include "pch.h"
#include "../EmployeeDB/Parser.h"
#include"../EmployeeDB/DataStructure.h"

TEST(ParserTset, ParseCmdLineTest) {
	string str = "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV";

	CmdPacket cmdPacket;
	Parser::ParseCmdLine(str, cmdPacket);

	EXPECT_EQ(0, cmdPacket.cmd.compare("ADD"));
	EXPECT_EQ(0, cmdPacket.option1.compare(" "));
	EXPECT_EQ(0, cmdPacket.option2.compare(" "));
	EXPECT_EQ(0, cmdPacket.option3.compare(" "));
	EXPECT_EQ(0, cmdPacket.data1.compare("15123099"));
	EXPECT_EQ(0, cmdPacket.data2.compare("VXIHXOTH JHOP"));
	EXPECT_EQ(0, cmdPacket.data3.compare("CL3"));
	EXPECT_EQ(0, cmdPacket.data4.compare("010-3112-2609"));
	EXPECT_EQ(0, cmdPacket.data5.compare("19771211"));
	EXPECT_EQ(0, cmdPacket.data6.compare("ADV"));
}

TEST(ParserTset, ParseNameTest) {
	string str = "VXIHXOTH JHOP";

	string firstName;
	string lastName;
	Parser::ParseName(str, firstName, lastName);

	EXPECT_TRUE(false);
}

TEST(ParserTset, ParsePhoneNumTest) {
	string str = "010-3112-2609";

	string middlePhoneNum;
	string lastPhoneNum;
	Parser::ParsePhoneNum(str, middlePhoneNum, lastPhoneNum);

	EXPECT_TRUE(false);
}

TEST(ParserTset, ParseBirthDayTest) {
	string str = "19771211";

	string year;
	string month;
	string day;
	Parser::ParseBirthDay(str, year, month, day);

	EXPECT_TRUE(false);
}

TEST(ParserTset, ParseOptionTest) {
	string str = "-p";

	OptionType optionType = Parser::ParseOption(str);

	EXPECT_TRUE(false);
}