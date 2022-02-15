#include "Adder.h"

#include "data_structure.h"

void Adder::Add(string employeeNum, string name, string cl, string phoneNum, string birthday, string certi) {
	Employee employee;

	employee.employeeNum = employeeNum;
	employee.name = name;
	employee.cl = cl;
	employee.phoneNum = phoneNum;
	employee.birthday = birthday;
	employee.certi = certi;
	employee.valid = 1;

	memberList[currentIndex] = employee;

	employeeNum_map.insert({ employeeNum, currentIndex });
	name_map.insert({ name, currentIndex });
	cl_map.insert({ cl, currentIndex });
	phoneNum_map.insert({ phoneNum, currentIndex });
	birthday_map.insert({ birthday, currentIndex });
	certi_map.insert({ certi, currentIndex });

	currentIndex++;
}