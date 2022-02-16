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

	EXPECT_EQ(0, firstName.compare("VXIHXOTH"));
	EXPECT_EQ(0, lastName.compare("JHOP"));
}

TEST(ParserTset, ParsePhoneNumTest) {
	string str = "010-3112-2609";

	string middlePhoneNum;
	string lastPhoneNum;
	Parser::ParsePhoneNum(str, middlePhoneNum, lastPhoneNum);

	EXPECT_EQ(0, middlePhoneNum.compare("3112"));
	EXPECT_EQ(0, lastPhoneNum.compare("2609"));
}

TEST(ParserTset, ParseBirthDayTest) {
	string str = "19771211";

	string year;
	string month;
	string day;
	Parser::ParseBirthDay(str, year, month, day);

	EXPECT_EQ(0, year.compare("1977"));
	EXPECT_EQ(0, month.compare("12"));
	EXPECT_EQ(0, day.compare("11"));

}

TEST(ParserTset, ParseOptionTest) {
	string str = "-p";

	OptionType optionType = Parser::ParseOption(str);

	EXPECT_EQ(OptionType::p, optionType);
}