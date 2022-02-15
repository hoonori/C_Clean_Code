#include "pch.h"
#include "../EmployeeDB/Parser.h"
#include"../EmployeeDB/DataStructure.h"

TEST(ParserTset, ParseTest) {
	Parser parser;

	string str = "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV";

	CmdPacket cmdPacket;
	parser.Parse(str, cmdPacket);

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