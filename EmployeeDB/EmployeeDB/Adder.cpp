#include "Adder.h"

#include "DataStructure.h"

Adder::Adder(DataBase* dataBase) {
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

	m_dataBase->CreateRecord(employee);
}
