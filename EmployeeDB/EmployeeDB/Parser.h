#pragma once

#include <string>

#include "DataStructure.h"

using namespace std;

class Parser
{
public:
	void Parse(string line, OUT CmdPacket& cmdPacket);
private:
};

