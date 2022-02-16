#include "Searcher.h"

Searcher::Searcher(DataBase* dataBase, Printer* printer) {
	m_dataBase = dataBase;
	m_Printer = printer;
	m_comm = "SCH";
	
}

bool Searcher::CallPrinter(Employee employee)
{
	string employNum = employee.employeeNum;
	string name = employee.name; 
	string cl = employee.cl; 
	string phoneNum = employee.phoneNum;
	string birthday = employee.birthday;
	string certi = employee.certi;

	//printf("%s,%s,%s,%s,%s,%s,%s\n",
	//	m_comm.c_str(),
	//	employNum.c_str(),
	//	name.c_str(),
	//	cl.c_str(),
	//	phoneNum.c_str(),
	//	birthday.c_str(),
	//	certi.c_str());
	//m_Printer->PrintRecord(m_comm, employNum, name, cl, phoneNum, birthday, certi);

	return true;
}

vector<int> Searcher::Search(KeyType keyType, string key)
{
	OptType opt1 = OptType::FirstName;
	OptType opt2 = OptType::FirstName;

	vector<int> resVec;
		
	switch (keyType) {
	 case KeyType::FirstName:
		 resVec = m_dataBase->FindMapAll(KeyType::FirstName, key);
		 break;
	 case KeyType::LastName:
		 resVec = m_dataBase->FindMapAll(KeyType::LastName, key);
		 break;
	 case KeyType::MiddlePhoneNum:
		 resVec = m_dataBase->FindMapAll(KeyType::MiddlePhoneNum, key);
		 break;
	 case KeyType::LastPhoneNum:
		 resVec = m_dataBase->FindMapAll(KeyType::LastPhoneNum, key);
		 break;
	 case KeyType::YearBirth:
		 resVec = m_dataBase->FindMapAll(KeyType::YearBirth, key);
		 break;
	 case KeyType::MonthBirth:
		 resVec = m_dataBase->FindMapAll(KeyType::MonthBirth, key);
		 break;
	 case KeyType::DayBirth:
		 resVec = m_dataBase->FindMapAll(KeyType::DayBirth, key);
		 break;
	 default :
		 resVec = m_dataBase->FindMapAll(keyType, key);
		 break;

	}

	int size = (int)resVec.size();

	if (size == 0) {
		m_Printer->PrintNone(m_comm);
		return resVec;
	}

	if (opt1 == OptType::Printer) {
		// vector sort
		Employee tempEmployee;
		vector<pair<unsigned long, int>> v;
		for (auto iter = resVec.begin(); iter != resVec.end(); iter++) {
			tempEmployee = m_dataBase->ReadRecord(*iter);
			unsigned long ul = stoul(tempEmployee.employeeNum);
			v.push_back(pair<unsigned long, int>(ul, resVec[*iter]));
		}
		sort(v.begin(), v.end());

		//vector 5°³ Ãâ·Â
		int cnt = 0;
		for (auto iter = v.begin(); iter != v.end(); iter++) {
			
			if (cnt > 4) {
				break;
			}

			Employee tempEmployee = m_dataBase->ReadRecord(iter->second);
			CallPrinter(tempEmployee);
			cnt++;
		}

	}
	else{
		m_Printer->PrintCount(m_comm, size);
	}

	return resVec;
}

