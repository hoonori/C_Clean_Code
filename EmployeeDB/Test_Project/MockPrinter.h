#pragma once

#include "pch.h"
#include "gmock/gmock.h"

#include "../EmployeeDB/IPrinter.h"

using namespace testing;

class MockPrinter : public IPrinter
{
public:
	MOCK_METHOD(void, PrintRecord, (string cmd, string employNum, string name, string cl, string phoneNum, string birthday, string certi), (override));
	MOCK_METHOD(void, PrintCount, (string cmd, int recordCount), (override));
	MOCK_METHOD(void, PrintNone, (string cmd), (override));
};