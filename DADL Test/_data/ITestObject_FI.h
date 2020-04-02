__forceinline ITestObject::ITestObject()
{ /* darf nie aufgerufen werden */ }

__forceinline ITestObject::~ITestObject()
{ /* darf nie aufgerufen werden */ }

__forceinline ITestObject* ITestObject::IsOfType(DataFoundationAccess::WObject* p_pObject)
{ return (ITestObject *)p_pObject->IsOfType(s_oclClassList.aulClass, s_oclClassList.ulLength); }

__forceinline const ITestObject* ITestObject::IsOfType(const DataFoundationAccess::WObject* p_pObject)
{ return (ITestObject *)p_pObject->IsOfType(s_oclClassList.aulClass, s_oclClassList.ulLength); }

__forceinline DataFoundation::stcObjectLink ITestObject::BuildLink(bool p_bAddRef)
{ return DataFoundation::stcObjectLink(GetId(), p_bAddRef ? (DataFoundation::stcObjectClassList *)s_oclClassList : NULL); }

__forceinline HRESULT ITestObject::ExternalAddRef()
{ return WObject_ClassAddRefData(this, s_oclClassList.aulClass, s_oclClassList.ulLength); }

__forceinline HRESULT ITestObject::ExternalRelease()
{ return WObject_ClassReleaseData(this, s_oclClassList.aulClass, s_oclClassList.ulLength); }

__forceinline void ITestObject::Load(const DataFoundation::UBitFlagSet* p_pbfsLoad, HANDLE p_hTransaction)
{ WObject_LoadData(this, p_pbfsLoad, p_hTransaction); }

__forceinline HRESULT ITestObject::DirectLoadExec(HANDLE p_hTransaction, const DataFoundation::UBitFlagSet* p_pbfsLoad)
{
	WObject_LoadData(this, p_pbfsLoad, p_hTransaction);
	return GetDomain()->Execute(p_hTransaction);
}

__forceinline HRESULT ITestObject::GetText(LPCWSTR* p_Value) const
{ return WObject_GetValue(this, s_aullClassId[0] | 0x00000ULL, p_Value); }

__forceinline HRESULT ITestObject::SetText(LPCWSTR p_Value)
{ return WObject_SetValue(this, s_aullClassId[0] | 0x00000ULL, (const void*)p_Value); }

__forceinline HRESULT ITestObject::GetNumber(INT32* p_Value) const
{ return WObject_GetValue(this, s_aullClassId[0] | 0x10000ULL, p_Value); }

__forceinline HRESULT ITestObject::SetNumber(INT32 p_Value)
{ return WObject_SetValue(this, s_aullClassId[0] | 0x10000ULL, (const void*)p_Value); }


