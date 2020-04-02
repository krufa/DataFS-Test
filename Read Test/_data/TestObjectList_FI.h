__forceinline TestObjectList::TestObjectList()
{}

__forceinline TestObjectList::~TestObjectList()
{}

__forceinline UINT32 TestObjectList::GetLength() const
{ return ((DataFoundation::UList *)this)->GetLength(); }

__forceinline HRESULT TestObjectList::Insert(UINT32* p_pulIndex, TestObjectListItem* p_pItem)
{ return ((DataFoundation::UList *)this)->Insert(p_pulIndex, p_pItem); }

__forceinline HRESULT TestObjectList::Remove(UINT32 p_ulIndex)
{ return ((DataFoundation::UList *)this)->Remove(p_ulIndex); }

__forceinline HRESULT TestObjectList::Remove(const DataFoundation::ObjectId* p_poiObjectId)
{
	for(UINT32 i = 0; i < ((DataFoundation::UList *)this)->GetLength(); i++)
	{
		const void* pItem;
		((DataFoundation::UList *)this)->Get(i, &pItem);
		if((*(DataFoundation::ObjectId*)pItem) == *p_poiObjectId)
		{
			((DataFoundation::UList *)this)->Remove(i);
			return S_OK;
		}
	}
	return S_FALSE;
}

__forceinline HRESULT TestObjectList::Get(UINT32 p_ulIndex, const TestObjectListItem** p_pItem) const
{ return ((DataFoundation::UList *)this)->Get(p_ulIndex, (const void**)p_pItem); }

__forceinline HRESULT TestObjectList::Set(UINT32 p_ulIndex, TestObjectListItem* p_pItem)
{ return ((DataFoundation::UList *)this)->Set(p_ulIndex, p_pItem); }


