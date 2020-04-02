#pragma once

class ITestObject : public DataFoundationAccess::WObject
{
private:
								ITestObject			();
								~ITestObject		();

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

	static	ITestObject*		IsOfType			(DataFoundationAccess::WObject* p_pObject);
	static	const ITestObject*	IsOfType			(const DataFoundationAccess::WObject* p_pObject);

			DataFoundation::stcObjectLink
								BuildLink			(bool p_bAddRef);

			HRESULT				ExternalAddRef		();
			HRESULT				ExternalRelease		();

			void				Load				(const DataFoundation::UBitFlagSet* p_pbfsLoad = ALL_ATTRIBUTES, HANDLE p_hTransaction = TRANSACTION_LOAD);
			HRESULT				DirectLoadExec		(HANDLE p_hTransaction, const DataFoundation::UBitFlagSet* p_pbfsLoad = ALL_ATTRIBUTES);

			HRESULT				GetText				(LPCWSTR* p_Value) const;
			HRESULT				SetText				(LPCWSTR p_Value);
			HRESULT				GetNumber			(INT32* p_Value) const;
			HRESULT				SetNumber			(INT32 p_Value);

	enum
	{
		Text = 0x0,
		Number = 0x1
	};
};

