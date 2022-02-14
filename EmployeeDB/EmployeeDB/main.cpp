#include <stdio.h>
#include <vector>

using namespace std;

int main() {

	//printf("hello world!\n");
	return 0;
}


struct Employee {
	char employeeNum[9];
	char name[15];
	char cl[4];
	char phoneNum[14];
	char birthday[9];
	char certi[4];
};


vector<Employee> memberList;