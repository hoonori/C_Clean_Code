#pragma once

#include <string>
#include <fstream>

using namespace std;

class Printer
{
public:
	Printer(ofstream* ofs);
	void PrintRecord(string cmd, string employNum, string name, string cl, string phoneNum, string birthday, string certi);
	void PrintCount(string cmd, int recordCount);
	void PrintNone(string cmd);
private:
	ofstream* m_outfileStream;
};

