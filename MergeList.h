#ifndef __MERGELIST_H__
#define __MERGELIST_H__

#include <iostream>
using namespace std;

struct ListNode
{
	int _data;
	ListNode* _next;
};

//递归实现单链表的合并
ListNode* MergeList(ListNode* phead1, ListNode* phead2)
{
	if (phead1 == NULL)
		return phead2;

	if (phead2 == NULL)
		return phead1;

	ListNode* pMergeHead = NULL;
	if (phead1->_data < phead2->_data)
	{
		pMergeHead = phead1;
		pMergeHead->_next = MergeList(phead1->_next, phead2);
	}
	else
	{
		pMergeHead = phead2;
		pMergeHead->_next = MergeList(phead1, phead2->_next);
	}

	return pMergeHead;
}


#endif //__MERGELIST_H__