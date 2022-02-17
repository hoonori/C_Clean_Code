#include "Adder.h"

#include "DataStructure.h"
#include "Parser.h"

Adder::Adder(IDataBase* dataBase) {
	m_dataBase = dataBase;
}

void Adder::Add(string employeeNum, string name, string cl, string phoneNum, string birthday, string certi) {
	Employee employee;

	employee.employeeNum = employeeNum;
	employee.name = name;
	employee.cl = cl;
	employee.phoneNum = phoneNum;
	employee.birthday = birthday;
	employee.certi = certi;
	employee.valid = true;

	// set additional parsing info
	Parser::ParseName(name, employee.firstName, employee.lastName);
	Parser::ParsePhoneNum(phoneNum, employee.middlePhoneNum, employee.lastPhoneNum);
	Parser::ParseBirthDay(birthday, employee.yearBirth, employee.monthBirth, employee.dayBirth);

	m_dataBase->CreateRecord(employee);
}
