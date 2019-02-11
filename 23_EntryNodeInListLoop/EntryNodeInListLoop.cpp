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

// ������23�������л�����ڽ��
// ��Ŀ��һ�������а�����������ҳ�������ڽ�㣿���磬��ͼ3.8�������У�
// ������ڽ���ǽ��3��

#include <cstdio>
#include <stdlib.h>
#include "../Utilities/list.h"

////³���ԣ��Ƿ���ڻ�
//ListNode* MeetingNode(ListNode* pHead)
//{
//	//1.³����1�����Ϊ����������nullptr
//    if(pHead == nullptr)
//        return nullptr;
//
//	//2.slow�ڵ���һ����
//    ListNode* pSlow = pHead->m_pNext;
//	//3.³����2�����ֻ��һ���ڵ㣬����nullptr
//    if(pSlow == nullptr)
//        return nullptr;
//	//4.fast�ڵ�������
//    ListNode* pFast = pSlow->m_pNext;
//	//5.whileѭ��������fast��slow����Ϊnullptrʱ
//    while(pFast != nullptr && pSlow != nullptr)
//    {
//		//5.1 ���fast��slow�����ˣ���������ڵ㣬����ڵ�һ���ڻ��С�
//        if(pFast == pSlow)
//            return pFast;
//
//		//5.2 slow ��һ��
//        pSlow = pSlow->m_pNext;
//
//		//5.3 fast ������
//        pFast = pFast->m_pNext;
//		//5.3.1 ³����3�����fast�ߵĵ�һ����Ϊnullptr���ͼ�����һ��
//        if(pFast != nullptr)
//            pFast = pFast->m_pNext;
//    }
//
//	//6.���û�������ͷ���nullptr
//    return nullptr;
//}
//
//
//ListNode* EntryNodeOfLoop(ListNode* pHead)
//{
//    ListNode* meetingNode = MeetingNode(pHead);
//    if(meetingNode == nullptr)
//        return nullptr;
//
//    // �õ����н�����Ŀ
//    int nodesInLoop = 1;
//    ListNode* pNode1 = meetingNode;
//    while(pNode1->m_pNext != meetingNode)
//    {
//        pNode1 = pNode1->m_pNext;
//        ++nodesInLoop;
//    }
//
//    // ���ƶ�pNode1������Ϊ���н�����Ŀ
//    pNode1 = pHead;
//    for(int i = 0; i < nodesInLoop; ++i)
//        pNode1 = pNode1->m_pNext;
//
//    // ���ƶ�pNode1��pNode2
//    ListNode* pNode2 = pHead;
//    while(pNode1 != pNode2)
//    {
//        pNode1 = pNode1->m_pNext;
//        pNode2 = pNode2->m_pNext;
//    }
//
//    return pNode1;
//}

//³���ԣ��Ƿ���ڻ�
ListNode* MeetingNode(ListNode* pHead)
{
	//1.³����1��ͷ�ڵ�Ϊ�գ����ؿ�
	if (!pHead)
		return nullptr;

	//2.slow����һ����ע��³����2�� ���slow�����ڷ���nullptr
	ListNode* slow = pHead->m_pNext;
	if (!slow)
		return nullptr;

	//3.fast������
	ListNode* fast = slow->m_pNext;

	//4.���fast��slow�����ڵ����
	while (fast&& slow)
	{
		//4.1 �������ָ�������ˣ����������ڵ�
		if (fast == slow)
			return fast;

		//4.2 slow���ߵ���һ��
		slow = slow->m_pNext;

		//4.3 fastҪ�����������ߵ�һ�����ڲ���³����֮���ߵڶ���
		fast = fast->m_pNext;
		if (fast)
		{
			fast = fast->m_pNext; 
		}
	}

	//5.���fast��slow��û������������nullptr
	return nullptr;
}

//�ҵ����
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	//1.³���Լ�飺�ж��Ƿ��л�,���û�У����ؿ�
	ListNode* MeetNode = MeetingNode(pHead);
	if (!MeetNode)
		return nullptr;

	//2.���û��ڽڵ������������1��ʼ
	int count = 1;

	//3.�½�һ��ָ��������ڵ����һ����
	ListNode* Node = MeetNode->m_pNext;
	
	//4.���߱߼������ߵ������Լ�Ϊֹ��
	while (Node&& (Node != MeetNode))
	{
		Node = Node->m_pNext;
		count++;
	}
	Node = nullptr;

	//5.����fast��n��
	ListNode* fast= pHead;
	for(int i=0;i<count;i++)
	{ 
		fast= fast->m_pNext; 
	}

	//6.slow��ʼ��
	ListNode* slow = pHead;
	while (slow&&fast)
	{
		if (slow == fast)
			return fast;

		slow = slow->m_pNext;
		fast = fast->m_pNext;
	}



}

// ==================== Test Code ====================
void Test(char* testName, ListNode* pHead, ListNode* entryNode)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);

    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test3()
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
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test4()
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
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test5()
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
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop 
void Test6()
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

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
	system("pause");
    return 0;
}
