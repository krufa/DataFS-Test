__forceinline ITestRoot::ITestRoot()
{ /* darf nie aufgerufen werden */ }

__forceinline ITestRoot::~ITestRoot()
{ /* darf nie aufgerufen werden */ }

__forceinline ITestRoot* ITestRoot::IsOfType(DataFoundationAccess::WObject* p_pObject)
{ return (ITestRoot *)p_pObject->IsOfType(s_oclClassList.aulClass, s_oclClassList.ulLength); }

__forceinline const ITestRoot* ITestRoot::IsOfType(const DataFoundationAccess::WObject* p_pObject)
{ return (ITestRoot *)p_pObject->IsOfType(s_oclClassList.aulClass, s_oclClassList.ulLength); }

__forceinline DataFoundation::stcObjectLink ITestRoot::BuildLink(bool p_bAddRef)
{ return DataFoundation::stcObjectLink(GetId(), p_bAddRef ? (DataFoundation::stcObjectClassList *)s_oclClassList : NULL); }

__forceinline HRESULT ITestRoot::ExternalAddRef()
{ return WObject_ClassAddRefData(this, s_oclClassList.aulClass, s_oclClassList.ulLength); }

__forceinline HRESULT ITestRoot::ExternalRelease()
{ return WObject_ClassReleaseData(this, s_oclClassList.aulClass, s_oclClassList.ulLength); }

__forceinline void ITestRoot::Load(const DataFoundation::UBitFlagSet* p_pbfsLoad, HANDLE p_hTransaction)
{ WObject_LoadData(this, p_pbfsLoad, p_hTransaction); }

__forceinline HRESULT ITestRoot::DirectLoadExec(HANDLE p_hTransaction, const DataFoundation::UBitFlagSet* p_pbfsLoad)
{
	WObject_LoadData(this, p_pbfsLoad, p_hTransaction);
	return GetDomain()->Execute(p_hTransaction);
}

__forceinline void ITestRoot::Create(ITestObject** p_ppITestObject, HANDLE p_hTransaction)
{ GetDomain()->Create((DataFoundationAccess::WObject **)p_ppITestObject, GetId(), ITestObject::s_oclClassList.aulClass, ITestObject::s_oclClassList.ulLength, p_hTransaction); }

__forceinline HRESULT ITestRoot::Open(ITestObject** p_ppITestObject, const DataFoundation::ObjectId* p_poiId, HANDLE p_hTransaction)
{ GetDomain()->Open((DataFoundationAccess::WObject **)p_ppITestObject, p_poiId, NULL, 0, p_hTransaction); return S_OK; }

__forceinline HRESULT ITestRoot::GetRootName(LPCWSTR* p_Value) const
{ return WObject_GetValue(this, s_aullClassId[0] | 0x00000ULL, p_Value); }

__forceinline HRESULT ITestRoot::SetRootName(LPCWSTR p_Value)
{ return WObject_SetValue(this, s_aullClassId[0] | 0x00000ULL, (const void*)p_Value); }

__forceinline HRESULT ITestRoot::GetAllObjects(const TestObjectList** p_Value) const
{ return WObject_GetValue(this, s_aullClassId[0] | 0x10000ULL, p_Value); }

__forceinline HRESULT ITestRoot::SetAllObjects(TestObjectList** p_Value)
{ return WObject_SetValue(this, s_aullClassId[0] | 0x10000ULL, (const void*)p_Value); }


