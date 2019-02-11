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

// ������18��һ������O(1)ʱ��ɾ��������
// ��Ŀ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ����
// ��㡣

#include <cstdio>
#include <stdlib.h>
#include "..\Utilities\List.h"

//void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
//{
//    if(!pListHead || !pToBeDeleted)
//        return;
//
//    // Ҫɾ���Ľ�㲻��β���
//    if(pToBeDeleted->m_pNext != nullptr)
//    {
//        ListNode* pNext = pToBeDeleted->m_pNext;
//        pToBeDeleted->m_nValue = pNext->m_nValue;
//        pToBeDeleted->m_pNext = pNext->m_pNext;
// 
//        delete pNext;
//        pNext = nullptr;
//    }
//    // ����ֻ��һ����㣬ɾ��ͷ��㣨Ҳ��β��㣩
//    else if(*pListHead == pToBeDeleted)
//    {
//        delete pToBeDeleted;
//        pToBeDeleted = nullptr;
//        *pListHead = nullptr;
//    }
//    // �������ж����㣬ɾ��β���
//    else
//    {
//        ListNode* pNode = *pListHead;
//        while(pNode->m_pNext != pToBeDeleted)
//        {
//            pNode = pNode->m_pNext;            
//        }
// 
//        pNode->m_pNext = nullptr;
//        delete pToBeDeleted;
//        pToBeDeleted = nullptr;
//    }
//}

//��֪�ýڵ����������
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	//1.�������ͷ�ڵ���ɾ���ڵ�Ϊ�գ�����
	if (!pListHead || !pToBeDeleted)
		return;
	//2.����ڵ������ǰn-1����β�ڵ�
	if (pToBeDeleted->m_pNext)
	{
		//2.1 pNext����ɾ���ڵ�J���¸��ڵ�K
		ListNode* pNext = pToBeDeleted->m_pNext;
		//2.2 ����ֵJ=K
		pToBeDeleted->m_nValue = pNext->m_nValue;
		//2.3 ����ָ��J->NEXT=K->NEXT
		pToBeDeleted->m_pNext = pNext->m_pNext;

		//2.4 ɾȥ�¸��ڵ�K(pNext)
		delete pNext;

		//2.5 pNext��Ϊ��ָ��
		pNext = nullptr;

	}

	//3.ֻ��һ���ڵ������ɾ��Ҫ��ͷ�ڵ�ָ����Ϊ��
	else if(*pListHead==pToBeDeleted)
	{
		//3.1ɾ���ڵ�
		delete pToBeDeleted; 

		//3.2 �ͷ�ɾ���ڵ��ָ��
		pToBeDeleted = nullptr;

		//3.3 ɾ����ͷ�ڵ���Ϊ��ָ��
		*pListHead = nullptr;

	}
	//4.��������һ��β�ڵ㣬���ñ���
	else
	{
		//4.1 pNode������ָ��,��ͷ��ʼ
		ListNode* pNode = *pListHead;
		//4.2 while�����ҵ�pNode����һ���ڵ���Ҫɾ���Ľڵ�
		while(pNode->m_pNext == pToBeDeleted)
		{ 
			//4.2.1 ָ�����ָ
			pNode = pNode->m_pNext; 
		}
		//4.3 ��pNode����һ���ڵ���Ϊ��
		pNode->m_pNext = nullptr;

		//4.4 ɾ�����Ľڵ�
		delete pToBeDeleted;
		//4.5 �ͷ�ָ�� 
		pToBeDeleted = nullptr; 

	}


}

// ====================���Դ���====================
void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);
    
    printf("The result list is: \n");
    PrintList(pListHead);
}

// �������ж����㣬ɾ���м�Ľ��
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

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��β���
void Test2()
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

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��ͷ���
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

    Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// ������ֻ��һ����㣬ɾ��ͷ���
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// ����Ϊ��
void Test5()
{
    Test(nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
	system("pause");
    return 0;
}

