#include "stdafx.h"


HRESULT AccessDefinition::GetInfo(HANDLE p_hInfo)
{
	// FEHLER, fehlt was ist das überhaupt!?!?
	return E_NOTIMPL;
}

HRESULT AccessDefinition::Bind(DataFoundationAccess::WDomain* p_pDomain)
{
	Foster::HSCHEMA hSchema = p_pDomain->GetSchema();
	Foster::UBitFlagSetSingle* pbfss;
	return S_OK;
}

HRESULT AccessDefinition::Unbind()
{
	return S_OK;
}


