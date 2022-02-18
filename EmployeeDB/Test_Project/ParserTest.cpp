#include "pch.h"
#include "../EmployeeDB/Parser.h"
#include"../EmployeeDB/DataStructure.h"

using namespace testing;

class ParserTest : public testing::Test
{
protected:
	void SetUp(void) override {

	}

	void TearDown(void) override {

	}
};
TEST_F(ParserTest, ParseCmdLineTest) {
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

TEST_F(ParserTest, ParseNameTest) {
	string str = "VXIHXOTH JHOP";

	string firstName;
	string lastName;
	Parser::ParseName(str, firstName, lastName);

	EXPECT_EQ(0, firstName.compare("VXIHXOTH"));
	EXPECT_EQ(0, lastName.compare("JHOP"));
}

TEST_F(ParserTest, ParsePhoneNumTest) {
	string str = "010-3112-2609";

	string middlePhoneNum;
	string lastPhoneNum;
	Parser::ParsePhoneNum(str, middlePhoneNum, lastPhoneNum);

	EXPECT_EQ(0, middlePhoneNum.compare("3112"));
	EXPECT_EQ(0, lastPhoneNum.compare("2609"));
}

TEST_F(ParserTest, ParseBirthDayTest) {
	string str = "19771211";

	string year;
	string month;
	string day;
	Parser::ParseBirthDay(str, year, month, day);

	EXPECT_EQ(0, year.compare("1977"));
	EXPECT_EQ(0, month.compare("12"));
	EXPECT_EQ(0, day.compare("11"));

}

TEST_F(ParserTest, ParseOptionTest) {
	string str = "-p";

	OptionType optionType = Parser::ParseOption(str);

	EXPECT_EQ(OptionType::p, optionType);
}

TEST_F(ParserTest, SortEmployeeTest) {
	
	vector<Employee> employVec;

	Employee employee1 = {true, "15123099", "JUNSEOK A", "CL4", "010-0000-0006", "970325", "EX"};
	Employee employee2 = { true, "69000000", "JUNSEOK B", "CL4", "010-0000-0006", "970325", "EX" };
	Employee employee3 = { true, "69000001", "JUNSEOK C", "CL4", "010-0000-0006", "970325", "EX" };
	Employee employee4 = { true, "88114052", "JUNSEOK D", "CL4", "010-0000-0006", "970325", "EX" };
	Employee employee5 = { true, "99999999", "JUNSEOK E", "CL4", "010-0000-0006", "970325", "EX" };
	Employee employee6 = { true, "21999998", "JUNSEOK F", "CL4", "010-0000-0006", "970325", "EX" };
	Employee employee7 = { true, "21999999", "JUNSEOK G", "CL4", "010-0000-0006", "970325", "EX" };
	Employee employee8 = { true, "00000000", "JUNSEOK G", "CL4", "010-0000-0006", "970325", "EX" };

	employVec.push_back(employee1);
	employVec.push_back(employee2);
	employVec.push_back(employee3);
	employVec.push_back(employee4);
	employVec.push_back(employee5);
	employVec.push_back(employee6);
	employVec.push_back(employee7);
	employVec.push_back(employee8);

	Parser::SortEmployee(employVec);

	Employee oldestEmployee = employVec.at(0);
	Employee youngestEmployee = employVec.at(7);

	EXPECT_EQ(0, oldestEmployee.employeeNum.compare("69000000"));
	EXPECT_EQ(0, youngestEmployee.employeeNum.compare("21999999"));
}

TEST_F(ParserTest, TranslateKeyTypeTest) {

	KeyType keyType;

	keyType = Parser::TranslateKeyType("employeeNum");
	EXPECT_EQ(KeyType::EmployeeNum, keyType);

	keyType = Parser::TranslateKeyType("name");
	EXPECT_EQ(KeyType::Name, keyType);

	keyType = Parser::TranslateKeyType("cl");
	EXPECT_EQ(KeyType::Cl, keyType);

	keyType = Parser::TranslateKeyType("phoneNum");
	EXPECT_EQ(KeyType::PhoneNum, keyType);

	keyType = Parser::TranslateKeyType("birthday");
	EXPECT_EQ(KeyType::Birthday, keyType);

	keyType = Parser::TranslateKeyType("certi");
	EXPECT_EQ(KeyType::Certi, keyType);
}

TEST_F(ParserTest, ChangeConditionTest) {
	
	EXPECT_EQ(KeyType::FirstName, Parser::ChangeCondition(KeyType::Name, OptionType::f));
	EXPECT_EQ(KeyType::LastName, Parser::ChangeCondition(KeyType::Name, OptionType::l));

	EXPECT_EQ(KeyType::MiddlePhoneNum, Parser::ChangeCondition(KeyType::PhoneNum, OptionType::m));
	EXPECT_EQ(KeyType::LastPhoneNum, Parser::ChangeCondition(KeyType::PhoneNum, OptionType::l));


	EXPECT_EQ(KeyType::YearBirth, Parser::ChangeCondition(KeyType::Birthday, OptionType::y));
	EXPECT_EQ(KeyType::MonthBirth, Parser::ChangeCondition(KeyType::Birthday, OptionType::m));
	EXPECT_EQ(KeyType::DayBirth, Parser::ChangeCondition(KeyType::Birthday, OptionType::d));
}