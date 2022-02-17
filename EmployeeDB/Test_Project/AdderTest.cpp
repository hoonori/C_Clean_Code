#include "pch.h"
#include "gmock/gmock.h"

#include "../EmployeeDB/Adder.h"
#include "../EmployeeDB/IDataBase.h"

#include "MockDataBase.h"

using namespace testing;

class AdderTest : public testing::Test
{
protected:
	void SetUp(void) override {
		mockDataBase = new MockDataBase();
		adder = new Adder(mockDataBase);
	}

	void TearDown(void) override {
		delete mockDataBase;
		delete adder;
	}

	MockDataBase* mockDataBase;
	Adder* adder;
};


TEST_F(AdderTest, AddTest) {

	string employeeNum = "15123099";
	string name = "VXIHXOTH JHOP";;
	string cl = "CL3";
	string phoneNum = "010-3112-2609";
	string birthday = "19771211";
	string certi = "ADV";

	EXPECT_CALL(*mockDataBase, CreateRecord(_)).Times(1);

	adder->Add(employeeNum, name, cl, phoneNum, birthday, certi);
}