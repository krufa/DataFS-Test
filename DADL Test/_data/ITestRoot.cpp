UINT64 ITestRoot::s_aullClassId[1];
UINT16 ITestRoot::s_ausAttributesCount[1];
DataFoundationAccess::stcObjectClassList<1> ITestRoot::s_oclClassList = { 1 };
DataFoundation::UBitFlagSet* ITestRoot::ALL_ATTRIBUTES = NULL;
DataFoundation::UBitFlagSet* ITestRoot::FIXED_ATTRIBUTES = NULL;

DataFoundation::UBitFlagSet* ITestRoot::CreateBitFlagSet(UINT32 p_ulCount, ...)
{
	UINT64 ullClassInfo = s_aullClassId[0] | UINT64(s_ausAttributesCount[0]);
	DataFoundation::UBitFlagSet* pbfs = DataFoundation::UBitFlagSet::Create(&ullClassInfo, 1);
	{
		va_list vaList;
		va_start(vaList, p_ulCount);
		for(UINT32 i = 0; i < p_ulCount; i++)
		{
			UINT32 ulParam = va_arg(vaList, UINT32);
				pbfs->Get(UINT32(s_aullClassId[ulParam >> 16] >> 32))->Set(ulParam & 0xffff);
		}
		va_end(vaList);
	}
	return pbfs;
}

