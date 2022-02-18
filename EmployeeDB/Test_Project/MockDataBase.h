#pragma once

#include "pch.h"
#include "gmock/gmock.h"

#include "../EmployeeDB/IDataBase.h"

using namespace testing;

class MockDataBase : public IDataBase
{
public:
	MOCK_METHOD(void, CreateRecord, (Employee employee), (override));
	MOCK_METHOD(Employee, ReadRecord, (int index), (override));
	MOCK_METHOD(void, UpdateRecord, (int index, string data, KeyType keyType), (override));
	MOCK_METHOD(void, DeleteRecord, (int index), (override));
	MOCK_METHOD(vector<int>, FindMapAll, (KeyType keyType, string key), (override));
};