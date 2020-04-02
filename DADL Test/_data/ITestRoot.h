#pragma once

class ITestRoot : public DataFoundationAccess::WObject
{
private:
								ITestRoot			();
								~ITestRoot			();

public:
	static	UINT64				s_aullClassId[1];
	static	UINT16				s_ausAttributesCount[1];
	static	DataFoundationAccess::stcObjectClassList<1>
								s_oclClassList;
	static	DataFoundation::UBitFlagSet*
								ALL_ATTRIBUTES;
	static	DataFoundation::UBitFlagSet*
								FIXED_ATTRIBUTES;

	static	DataFoundation::UBitFlagSet*
								CreateBitFlagSet	(UINT32 p_ulCount, ...);

	static	ITestRoot*			IsOfType			(DataFoundationAccess::WObject* p_pObject);
	static	const ITestRoot*	IsOfType			(const DataFoundationAccess::WObject* p_pObject);

			DataFoundation::stcObjectLink
								BuildLink			(bool p_bAddRef);

			HRESULT				ExternalAddRef		();
			HRESULT				ExternalRelease		();

			void				Load				(const DataFoundation::UBitFlagSet* p_pbfsLoad = ALL_ATTRIBUTES, HANDLE p_hTransaction = TRANSACTION_LOAD);
			HRESULT				DirectLoadExec		(HANDLE p_hTransaction, const DataFoundation::UBitFlagSet* p_pbfsLoad = ALL_ATTRIBUTES);

			void				Create				(ITestObject** p_ppITestObject, HANDLE p_hTransaction = TRANSACTION_STORE);
			HRESULT				Open				(ITestObject** p_ppITestObject, const DataFoundation::ObjectId* p_poiId, HANDLE p_hTransaction = TRANSACTION_LOAD);
			HRESULT				GetRootName			(LPCWSTR* p_Value) const;
			HRESULT				SetRootName			(LPCWSTR p_Value);
			HRESULT				GetAllObjects		(const TestObjectList** p_Value) const;
			HRESULT				SetAllObjects		(TestObjectList** p_Value);

	enum
	{
		RootName = 0x0,
		AllObjects = 0x1
	};
};

