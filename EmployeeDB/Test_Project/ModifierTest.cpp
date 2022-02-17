#include "pch.h"
#include "../EmployeeDB/Adder.h"
#include "../EmployeeDB/Modifier.h"
#include "../EmployeeDB/DataBase.h"


TEST(ModifierTest, ModTest) {
	DataBase* db = new DataBase();
	Adder* adder = new Adder(db);
	ofstream writeFile;
	writeFile.open("test.txt");
	Printer* printer = new Printer(&writeFile);
	Modifier* modifier = new Modifier(db, printer);

	string employeeNum = "15123099";
	string name = "VXIHXOTH JHOP";
	string cl = "CL3";
	string phoneNum = "010-3112-2609";
	string birthday = "19771211";
	string certi = "ADV";

	adder->Add(employeeNum, name, cl, phoneNum, birthday, certi);

	employeeNum = "21123099";
	name = "VXIHXOTH HHOP";
	cl = "CL3";
	phoneNum = "010-1234-2609";
	birthday = "19771212";
	certi = "PRO";

	adder->Add(employeeNum, name, cl, phoneNum, birthday, certi);

	modifier->Modify(KeyType::Cl, "CL3", KeyType::Certi, "EX", OptionType::none, OptionType::none);

	EXPECT_EQ("EX", db->ReadRecord(0).certi);
	EXPECT_EQ("EX", db->ReadRecord(1).certi);

	modifier->Modify(KeyType::Name, "VXIHXOTH HHOP", KeyType::Birthday, "20000101", OptionType::none, OptionType::none);
	EXPECT_EQ("20000101", db->ReadRecord(1).birthday);
	EXPECT_NE("20000101", db->ReadRecord(0).birthday);

	//Test option 2
	modifier->Modify(KeyType::Name, "HHOP", KeyType::Birthday, "21001101", OptionType::none, OptionType::l);
	EXPECT_EQ("21001101", db->ReadRecord(1).birthday);

	modifier->Modify(KeyType::Name, "VXIHXOTH", KeyType::Certi, "ADV", OptionType::none, OptionType::f);
	EXPECT_EQ("ADV", db->ReadRecord(0).certi);
	EXPECT_EQ("ADV", db->ReadRecord(1).certi);

	//Test option 1
	modifier->Modify(KeyType::Certi, "ADV", KeyType::Certi, "EX", OptionType::p, OptionType::none);

	writeFile.close();

	ifstream readFile;
	string totalStr = "";
	readFile.open("test.txt");
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			string str;
			getline(readFile, str);
			totalStr = totalStr + '\n' + str;
		}
		readFile.close();
	}
	EXPECT_EQ("\nMOD,2\nMOD,1\nMOD,1\nMOD,2\nMOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV\nMOD,21123099,VXIHXOTH HHOP,CL3,010-1234-2609,21001101,ADV\n", totalStr);



}