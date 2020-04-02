#pragma once



class AccessDefinition
{
public:
	static	HRESULT				GetInfo				(HANDLE p_hInfo);

	static	HRESULT				Bind				(DataFoundationAccess::WDomain* p_pDomain);
	static	HRESULT				Unbind				();


};





