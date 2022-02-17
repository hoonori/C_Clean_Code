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

TEST(ModifierTest, OptionTest) {
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
	name = "Park HHOP";
	cl = "CL3";
	phoneNum = "010-1234-1234";
	birthday = "19880912";
	certi = "PRO";

	adder->Add(employeeNum, name, cl, phoneNum, birthday, certi);

	modifier->Modify(KeyType::EmployeeNum, "15123099", KeyType::Name, "Junseok Yoon", OptionType::p, OptionType::f);

	
	writeFile.close();

	ifstream readFile;
	string totalStr = "";

	Employee res = db->ReadRecord(0);

	EXPECT_EQ(res.firstName.compare("Junseok"), 0);
	EXPECT_EQ(res.lastName.compare("Yoon"), 0);
	
	modifier->Modify(KeyType::EmployeeNum, "15123099", KeyType::PhoneNum, "010-8927-0425", OptionType::p, OptionType::none);

	res = db->ReadRecord(0);

	EXPECT_EQ(res.middlePhoneNum.compare("8927"), 0);
	EXPECT_EQ(res.lastPhoneNum.compare("0425"), 0);

	modifier->Modify(KeyType::EmployeeNum, "15123099", KeyType::Birthday, "19930317", OptionType::p, OptionType::none);

	res = db->ReadRecord(0);

	EXPECT_EQ(res.yearBirth.compare("1993"), 0);
	EXPECT_EQ(res.monthBirth.compare("03"), 0);
	EXPECT_EQ(res.dayBirth.compare("17"), 0);



	vector<int> resVector = db->FindMapAll(KeyType::FirstName, "Junseok");
	EXPECT_EQ(1, resVector.size());

	resVector = db->FindMapAll(KeyType::LastName, "Yoon");
	EXPECT_EQ(1, resVector.size());

	resVector = db->FindMapAll(KeyType::MiddlePhoneNum, "8927");
	EXPECT_EQ(1, resVector.size());

	resVector = db->FindMapAll(KeyType::LastPhoneNum, "0425");
	EXPECT_EQ(1, resVector.size());

	resVector = db->FindMapAll(KeyType::YearBirth, "1993");
	EXPECT_EQ(1, resVector.size());

	resVector = db->FindMapAll(KeyType::MonthBirth, "03");
	EXPECT_EQ(1, resVector.size());

	resVector = db->FindMapAll(KeyType::DayBirth, "17");
	EXPECT_EQ(1, resVector.size());

	resVector = db->FindMapAll(KeyType::Name, "Junseok Yoon");
	EXPECT_EQ(1, resVector.size());

	resVector = db->FindMapAll(KeyType::PhoneNum, "010-8927-0425");
	EXPECT_EQ(1, resVector.size());

	resVector = db->FindMapAll(KeyType::Birthday, "19930317");
	EXPECT_EQ(1, resVector.size());


	// check if former data is not erased
	resVector = db->FindMapAll(KeyType::FirstName, "VXIHXOTH");
	EXPECT_EQ(0, resVector.size());

	resVector = db->FindMapAll(KeyType::LastName, "JHOP");
	EXPECT_EQ(0, resVector.size());

	resVector = db->FindMapAll(KeyType::MiddlePhoneNum, "3112");
	EXPECT_EQ(0, resVector.size());

	resVector = db->FindMapAll(KeyType::LastPhoneNum, "2609");
	EXPECT_EQ(0, resVector.size());

	resVector = db->FindMapAll(KeyType::YearBirth, "1977");
	EXPECT_EQ(0, resVector.size());

	resVector = db->FindMapAll(KeyType::MonthBirth, "12");
	EXPECT_EQ(0, resVector.size());

	resVector = db->FindMapAll(KeyType::DayBirth, "11");
	EXPECT_EQ(0, resVector.size());

	resVector = db->FindMapAll(KeyType::Name, "VXIHXOTH JHOP");
	EXPECT_EQ(0, resVector.size());

	resVector = db->FindMapAll(KeyType::PhoneNum, "010-3112-2609");
	EXPECT_EQ(0, resVector.size());

	resVector = db->FindMapAll(KeyType::Birthday, "19771211");
	EXPECT_EQ(0, resVector.size());
}