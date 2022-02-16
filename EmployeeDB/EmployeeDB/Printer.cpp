#include "Printer.h"

Printer::Printer(ofstream* ofs) {
	m_outfileStream = ofs;
}

void Printer::PrintRecord(string cmd, string employNum, string name, string cl, string phoneNum, string birthday, string certi) {
	string str;

	str += cmd + ", ";
	str += employNum + ", ";
	str += name + ", ";
	str += cl + ", ";
	str += phoneNum + ", ";
	str += birthday + ", ";
	str += certi;

	*m_outfileStream << str << endl;
}

void Printer::PrintCount(string cmd, int recordCount) {
	string str;

	str += cmd + ", ";
	str += to_string(recordCount);

	*m_outfileStream << str << endl;
}

void Printer::PrintNone(string cmd) {
	string str;

	str += cmd + ", ";
	str += "NONE";

	*m_outfileStream << str << endl;
}