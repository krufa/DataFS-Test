#include "TestObjectList.cpp"
#include "ITestRoot.cpp"
#include "ITestObject.cpp"

HRESULT AccessDefinition::GetInfo(HANDLE p_hInfo)
{
	// FEHLER, fehlt was ist das überhaupt!?!?
	return E_NOTIMPL;
}

HRESULT AccessDefinition::Bind(DataFoundationAccess::WDomain* p_pDomain)
{
	DataFoundation::HSCHEMA hSchema = p_pDomain->GetSchema();
	DataFoundation::UBitFlagSetSingle* pbfss;
	{
		HRESULT hRes;
		const GUID guidGlobalId = { 0x1b013db1, 0x5219, 0x4363, { 0x9e, 0x02, 0xbd, 0x85, 0xd7, 0xe2, 0x44, 0x13 } };
		ITestRoot::s_oclClassList.aulClass[0] = 0; ITestRoot::s_ausAttributesCount[0] = 0;
		if(FAILED(hRes = DataFoundation::Schema_FindClassInfo(hSchema, &ITestRoot::s_oclClassList.aulClass[0], &ITestRoot::s_ausAttributesCount[0], &guidGlobalId)))
		{ Unbind(); return hRes; }
		ITestRoot::s_aullClassId[0] = UINT64(ITestRoot::s_oclClassList.aulClass[0]) << 32;
	}
	{
		UINT64 paClassInfo[1];
		paClassInfo[0] = ITestRoot::s_aullClassId[0] | UINT64(ITestRoot::s_ausAttributesCount[0]);
		ITestRoot::ALL_ATTRIBUTES = DataFoundation::UBitFlagSet::Create(paClassInfo, 1);
		pbfss = ITestRoot::ALL_ATTRIBUTES->Get(ITestRoot::s_oclClassList.aulClass[0]);
		{
			const UINT16 ausBfss[] = { 0x3 };
			pbfss->Copy(ausBfss);
		}
	}

	{
		HRESULT hRes;
		const GUID guidGlobalId = { 0xb06e97e6, 0x15d7, 0x4b70, { 0xb9, 0x4f, 0x67, 0x9f, 0x85, 0x8e, 0x0f, 0xe8 } };
		ITestObject::s_oclClassList.aulClass[0] = 0; ITestObject::s_ausAttributesCount[0] = 0;
		if(FAILED(hRes = DataFoundation::Schema_FindClassInfo(hSchema, &ITestObject::s_oclClassList.aulClass[0], &ITestObject::s_ausAttributesCount[0], &guidGlobalId)))
		{ Unbind(); return hRes; }
		ITestObject::s_aullClassId[0] = UINT64(ITestObject::s_oclClassList.aulClass[0]) << 32;
	}
	{
		UINT64 paClassInfo[1];
		paClassInfo[0] = ITestObject::s_aullClassId[0] | UINT64(ITestObject::s_ausAttributesCount[0]);
		ITestObject::ALL_ATTRIBUTES = DataFoundation::UBitFlagSet::Create(paClassInfo, 1);
		pbfss = ITestObject::ALL_ATTRIBUTES->Get(ITestObject::s_oclClassList.aulClass[0]);
		{
			const UINT16 ausBfss[] = { 0x3 };
			pbfss->Copy(ausBfss);
		}
	}

	return S_OK;
}

HRESULT AccessDefinition::Unbind()
{
	DataFoundation::UBitFlagSet::Destroy(ITestRoot::ALL_ATTRIBUTES);
	DataFoundation::UBitFlagSet::Destroy(ITestObject::ALL_ATTRIBUTES);
	return S_OK;
}

void AccessDefinition::Create(DataFoundationAccess::WDomain* p_pDomain, ITestRoot** p_ppITestRoot, HANDLE p_hTransaction)
{ p_pDomain->Create((DataFoundationAccess::WObject **)p_ppITestRoot, &(DataFoundation::OBJECTID_NULL), ITestRoot::s_oclClassList.aulClass, ITestRoot::s_oclClassList.ulLength, p_hTransaction); }

HRESULT AccessDefinition::Open(DataFoundationAccess::WDomain* p_pDomain, ITestRoot** p_ppITestRoot, const DataFoundation::ObjectId* p_poiId, HANDLE p_hTransaction)
{ return p_pDomain->Open((DataFoundationAccess::WObject **)p_ppITestRoot, p_poiId, NULL, 0, p_hTransaction); }


