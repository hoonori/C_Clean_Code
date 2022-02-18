#pragma once

#include <string>
#include <fstream>

using namespace std;

class IPrinter
{
public:
	virtual void PrintRecord(string cmd, string employNum, string name, string cl, string phoneNum, string birthday, string certi) = 0;
	virtual void PrintCount(string cmd, int recordCount) = 0;
	virtual void PrintNone(string cmd) = 0;
private:
};

