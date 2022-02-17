#include "Searcher.h"
#include "Parser.h"

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
	m_Printer->PrintRecord(m_comm, employNum, name, cl, phoneNum, birthday, certi);

	return true;
}

bool Searcher::isNumber(const string& str)
{
	for (char const& c : str) {
		if (std::isdigit(c) == 0) return false;
	}
	return true;
}

bool Searcher::Search(KeyType keyType, string key, OptionType ot1, OptionType ot2)
{
	vector<int> resVec = m_dataBase->FindMapAll(Parser::ChangeCondition(keyType,ot2), key);

	int size = (int)resVec.size();

	if (size == 0) {
		m_Printer->PrintNone(m_comm);
		return true;
	}

	if (ot1 == OptionType::p) {
		vector<Employee> employVec;

		for (auto iter = resVec.begin(); iter != resVec.end(); iter++) {
			employVec.push_back(m_dataBase->ReadRecord(*iter));
		}

		Parser::SortEmployee(employVec);

		int cnt = 0;
		for (int i = 0; i < employVec.size(); i++) {
			if (cnt > 4) {
				break;
			}
			CallPrinter(employVec.at(i));
			cnt++;
		}

	}
	else{
		m_Printer->PrintCount(m_comm, size);
	}

	return true;
}

