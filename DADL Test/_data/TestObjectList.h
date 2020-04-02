#pragma once

struct TestObjectListItem
{
			DataFoundation::stcObjectLink
								anObject;
			INT32				theType;
};

class TestObjectList
{
private:
								TestObjectList		();
								~TestObjectList		();

public:
			UINT32				GetLength			() const;

			HRESULT				Insert				(UINT32* p_pulIndex, TestObjectListItem* p_pItem);
			HRESULT				Remove				(UINT32 p_ulIndex);
			HRESULT				Remove				(const DataFoundation::ObjectId* p_poiObjectId);

			HRESULT				Get					(UINT32 p_ulIndex, const TestObjectListItem** p_pItem) const;
			HRESULT				Set					(UINT32 p_ulIndex, TestObjectListItem* p_pItem);
};


