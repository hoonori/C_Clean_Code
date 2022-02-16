#include "pch.h"
#include "../EmployeeDB/Searcher.h"
#include "../EmployeeDB/DataBase.h"
#include "../EmployeeDB/Printer.h"

TEST(SearcherTest, TestName) {

	ofstream ofs2;
	ofs2.open("test.txt");

	DataBase* database = new DataBase();
	Printer* printer = new Printer(&ofs2);
	Searcher* searcher = new Searcher(database, printer);

	Employee employee1;

	employee1.employeeNum = "2015123099";
	employee1.name = "VXIHXOTH JHOP";
	employee1.cl = "CL3";
	employee1.phoneNum = "010 - 3112 - 2609";
	employee1.birthday = "19771211";
	employee1.certi = "ADV";
	employee1.valid = true;

	Employee employee2;

	employee2.employeeNum = "2017112609";
	employee2.name = "FB NTAWR";
	employee2.cl = "CL3";
	employee2.phoneNum = "010 - 5645 - 6122";
	employee2.birthday = "19861203";
	employee2.certi = "PRO";
	employee2.valid = true;

	Employee employee3;

	employee3.employeeNum = "2018115040";
	employee3.name = "TTETHU HBO";
	employee3.cl = "CL3";
	employee3.phoneNum = "010-4581-2050";
	employee3.birthday = "20080718";
	employee3.certi = "ADV";
	employee3.valid = true;

	Employee employee4;

	employee4.employeeNum = "2089123099";
	employee4.name = "VXIHXOTH JHOP";
	employee4.cl = "CL3";
	employee4.phoneNum = "010 - 3112 - 2609";
	employee4.birthday = "19771211";
	employee4.certi = "ADV";
	employee4.valid = true;

	Employee employee5;

	employee5.employeeNum = "2179123099";
	employee5.name = "VXIHXOTH JHOP";
	employee5.cl = "CL3";
	employee5.phoneNum = "010 - 3112 - 2609";
	employee5.birthday = "19771211";
	employee5.certi = "ADV";
	employee5.valid = true;

	Employee employee6;

	employee6.employeeNum = "1999123099";
	employee6.name = "VXIHXOTH JHOP";
	employee6.cl = "CL3";
	employee6.phoneNum = "010 - 3112 - 2609";
	employee6.birthday = "19771211";
	employee6.certi = "ADV";
	employee6.valid = true;

	Employee employee7;

	employee7.employeeNum = "1899123099";
	employee7.name = "VXIHXOTH JHOP";
	employee7.cl = "CL4";
	employee7.phoneNum = "010 - 3112 - 2609";
	employee7.birthday = "19771211";
	employee7.certi = "ADV";
	employee7.valid = true;

	database->CreateRecord(employee1);
	database->CreateRecord(employee2);
	database->CreateRecord(employee3);
	database->CreateRecord(employee4);
	database->CreateRecord(employee5);
	database->CreateRecord(employee6);
	database->CreateRecord(employee7);

	vector<int> resVec = searcher->Search(KeyType::Cl, "CL3");
	EXPECT_EQ(6, resVec.size());

	resVec = searcher->Search(KeyType::Cl, "CL4");
	EXPECT_EQ(1, resVec.size());

	resVec = searcher->Search(KeyType::Certi, "PRO");
	EXPECT_EQ(1, resVec.size());

	resVec = searcher->Search(KeyType::Certi, "ADV");
	EXPECT_EQ(2, resVec.size());

	resVec = searcher->Search(KeyType::FirstName, "JHOP");
	EXPECT_EQ(2, resVec.size());


}