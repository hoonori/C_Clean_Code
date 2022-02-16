#include "pch.h"
#include "../EmployeeDB/DataBase.h"
#include "../EmployeeDB/DataStructure.h"
TEST(DataBaseTest, ReadTest) {
	DataBase* database = new DataBase();

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

	database->CreateRecord(employee1);
	database->CreateRecord(employee2);

	Employee res1 = database->ReadRecord(0);
	Employee res2 = database->ReadRecord(1);
	Employee res3 = database->ReadRecord(2);

	EXPECT_EQ(0, res1.employeeNum.compare("15123099"));
	EXPECT_EQ(0, res2.phoneNum.compare("010 - 5645 - 6122"));
	EXPECT_FALSE(res3.valid);
}
TEST(DataBaseTest, UpdateTest) {

	DataBase* database = new DataBase();

	Employee employee;

	employee.employeeNum = "15123099";
	employee.name = "VXIHXOTH JHOP";
	employee.cl = "CL3";
	employee.phoneNum = "010 - 3112 - 2609";
	employee.birthday = "19771211";
	employee.certi = "ADV";
	employee.valid = true;

	database->CreateRecord(employee);

	Employee res = database->ReadRecord(0);
	EXPECT_EQ(0, res.cl.compare("CL3"));


	string newData =  "CL4";

	database->UpdateRecord(0, newData, KeyType::Cl);

	res = database->ReadRecord(0);
	EXPECT_EQ(0, res.cl.compare("CL4"));
}

TEST(DataBaseTest, DeleteTest) {
	DataBase* database = new DataBase();

	Employee employee;

	employee.employeeNum = "15123099";
	employee.name = "VXIHXOTH JHOP";
	employee.cl = "CL3";
	employee.phoneNum = "010 - 3112 - 2609";
	employee.birthday = "19771211";
	employee.certi = "ADV";
	employee.valid = true;

	database->CreateRecord(employee);

	Employee res = database->ReadRecord(0);
	EXPECT_EQ(0, res.employeeNum.compare("15123099"));

	database->DeleteRecord(0);
	res = database->ReadRecord(0);
	
	EXPECT_EQ(false, res.valid);
}

TEST(DataBaseTest, FindAllTest) {
	DataBase* database = new DataBase();

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

	vector<int> resVec = database->FindMapAll(KeyType::Cl, "CL3");

	EXPECT_EQ(2, resVec.size());
}