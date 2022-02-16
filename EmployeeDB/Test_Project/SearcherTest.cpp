#include "pch.h"
#include "../EmployeeDB/Searcher.h"
#include "../EmployeeDB/DataBase.h"

TEST(SearcherTest, TestName) {
	DataBase* database = new DataBase();
	Searcher* searcher = new Searcher(database);

	Employee employee1;

	employee1.employeeNum = "15123099";
	employee1.name = "VXIHXOTH JHOP";
	employee1.cl = "CL3";
	employee1.phoneNum = "010 - 3112 - 2609";
	employee1.birthday = "19771211";
	employee1.certi = "ADV";
	employee1.valid = true;

	Employee employee2;

	employee2.employeeNum = "17112609";
	employee2.name = "FB NTAWR";
	employee2.cl = "CL4";
	employee2.phoneNum = "010 - 5645 - 6122";
	employee2.birthday = "19861203";
	employee2.certi = "PRO";
	employee2.valid = true;

	Employee employee3;

	employee3.employeeNum = "18115040";
	employee3.name = "TTETHU HBO";
	employee3.cl = "CL3";
	employee3.phoneNum = "010-4581-2050";
	employee3.birthday = "20080718";
	employee3.certi = "ADV";
	employee3.valid = true;

	database->CreateRecord(employee1);
	database->CreateRecord(employee2);
	database->CreateRecord(employee3);

	vector<int> resVec = searcher->Search(KeyType::Cl, "CL3");
	EXPECT_EQ(2, resVec.size());

	resVec = searcher->Search(KeyType::Cl, "CL4");
	EXPECT_EQ(1, resVec.size());

	resVec = searcher->Search(KeyType::Certi, "PRO");
	EXPECT_EQ(1, resVec.size());

	resVec = searcher->Search(KeyType::Certi, "ADV");
	EXPECT_EQ(2, resVec.size());
}