/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������24��	
// ��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������
// ͷ��㡣
#include <stdlib.h>
#include <cstdio>
#include "..\Utilities\List.h"

//ListNode* ReverseList(ListNode* pHead)
//{
//    ListNode* pReversedHead = nullptr;
//    ListNode* pNode = pHead;
//    ListNode* pPrev = nullptr;
//    while(pNode != nullptr)
//    {
//        ListNode* pNext = pNode->m_pNext;
//
//        if(pNext == nullptr)
//            pReversedHead = pNode;
//
//        pNode->m_pNext = pPrev;
//
//        pPrev = pNode;
//        pNode = pNext;
//    }
//
//    return pReversedHead;
//}

//ListNode* ReverseList(ListNode* pHead)
//{
//	//1.³��1����������nullptr
//	if (!pHead)
//		return nullptr;
//
//	//2.��������ָ��pPre,pNode,pNext��ReverseHead
//	ListNode* pNode = pHead;
//	ListNode* pPre = nullptr;
//	ListNode* pNext = nullptr;
//	ListNode* ReverseHead = nullptr;
//
//	//3.while(pNode)
//	while (pNode)
//	{
//		//3.1 ��¼�¸��ڵ�
//		pNext = pNode->m_pNext;
//
//		//3.2 �����β�ڵ㣬����ReverseHead = pNode;
//		if (!pNext)
//			ReverseHead = pNode;
//
//		//3.3 ��ת�ڵ�
//		pNode->m_pNext = pPre;
//
//		//3.4 ����pPre,pNode
//		pPre = pNode;
//		pNode = pNext;
//
//	}
//
//	//4.����ReverseHead
//	return ReverseHead;
//}

// //�ݹ�
//ListNode* ReverseList(ListNode* pHead) {
//	//�������Ϊ�ջ���������ֻ��һ��Ԫ��
//	if (pHead == NULL || pHead->m_pNext == NULL) return pHead;
//
//	//�ȷ�ת����������ߵ������ĩ�˽��
//	ListNode* pReverseNode = ReverseList(pHead->m_pNext);
//
//	//�ٽ���ǰ�ڵ�����Ϊ����ڵ�ĺ����ڵ�
//	pHead->m_pNext->m_pNext = pHead;
//
//	//�Ͽ���ǰ�ڵ��ԭ����ĺ����ڵ�
//	pHead->m_pNext = NULL;
//
//	return pReverseNode;
//}

//�ݹ�
ListNode* ReverseList(ListNode* pHead)
{
	//1.�������� �� ������������� ֻ��һ���ڵ㣬����pHead
	if (!pHead || !(pHead->m_pNext))
		return pHead;

	//2.�������ͷ�ڵ� ���ݹ���һ���ڵ㣬�ݹ鵽���һ���ڵ�ʱ���������һ���ڵ�
	ListNode* ReverseHead = ReverseList(pHead->m_pNext);

	//3.��ת��pNode->next->next=pNode
	pHead->m_pNext->m_pNext = pHead;

	//4.����ԭ�����pNode->next��Ϊ�գ��Ͽ�
	pHead->m_pNext = nullptr;
	
	//5.�����������ͷ�ڵ�
	return ReverseHead;
}

// ====================���Դ���====================
ListNode* Test(ListNode* pHead)
 {
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// ����������ж�����
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ���������ֻ��һ�����
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ���������
void Test3()
{
    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
	system("pause");
    return 0;
}

