#pragma once

#include <string>
#include <fstream>

#include "IPrinter.h"

using namespace std;

class Printer : public IPrinter
{
public:
	Printer(ofstream* ofs);
	void PrintRecord(string cmd, string employNum, string name, string cl, string phoneNum, string birthday, string certi) override;
	void PrintCount(string cmd, int recordCount) override;
	void PrintNone(string cmd) override;
private:
	ofstream* m_outfileStream;
};

