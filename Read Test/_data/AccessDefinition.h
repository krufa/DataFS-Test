#pragma once


class TestObjectList;
struct TestObjectListItem;
class ITestRoot;
class ITestObject;

class AccessDefinition
{
public:
	static	HRESULT				GetInfo				(HANDLE p_hInfo);

	static	HRESULT				Bind				(DataFoundationAccess::WDomain* p_pDomain);
	static	HRESULT				Unbind				();

	static	void				Create				(DataFoundationAccess::WDomain* p_pDomain, ITestRoot** p_ppITestRoot, HANDLE p_hTransaction = TRANSACTION_STORE);
	static	HRESULT				Open				(DataFoundationAccess::WDomain* p_pDomain, ITestRoot** p_ppITestRoot, const DataFoundation::ObjectId* p_poiId, HANDLE p_hTransaction = TRANSACTION_LOAD);

};


#include "TestObjectList.h"
#include "ITestRoot.h"
#include "ITestObject.h"


#include "TestObjectList_FI.h"
#include "ITestRoot_FI.h"
#include "ITestObject_FI.h"

