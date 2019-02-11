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

// ������18��������ɾ���������ظ��Ľ��
// ��Ŀ����һ������������У����ɾ���ظ��Ľ�㣿���磬��ͼ3.4��a�����ظ�
// ��㱻ɾ��֮��������ͼ3.4��b����ʾ��

#include <cstdio>
#include <stdlib.h>
#include "../Utilities/list.h" 

//void DeleteDuplication(ListNode** pHead)
//{
//    if(pHead == nullptr || *pHead == nullptr)
//        return;
//
//    ListNode* pPreNode = nullptr;
//    ListNode* pNode = *pHead;
//    while(pNode != nullptr)
//    {
//        ListNode *pNext = pNode->m_pNext;
//        bool needDelete = false;
//        if(pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
//            needDelete = true;
//
//        if(!needDelete)
//        {
//            pPreNode = pNode;
//            pNode = pNode->m_pNext;
//        }
//        else
//        {
//            int value = pNode->m_nValue;
//            ListNode* pToBeDel = pNode;
//            while(pToBeDel != nullptr && pToBeDel->m_nValue == value)
//            {
//                pNext = pToBeDel->m_pNext;
//
//                delete pToBeDel;
//                pToBeDel = nullptr;
//
//                pToBeDel = pNext;
//            }
//
//            if(pPreNode == nullptr)
//                *pHead = pNext;
//            else
//                pPreNode->m_pNext = pNext;
//            pNode = pNext;
//        }
//    }
//}

//�����Ĳ���:ListNode** pHead��
//��Ϊͷ�ڵ�����ظ����ᱻɾ�������Բ���ListNode* pHead
void DeleteDuplication(ListNode** pHead) 
{
	//1.����ǿ������ͷ�ڵ�Ϊ�գ����� 
	if (!pHead || !*pHead) 
		return;
	 
	//2.ListNode* pNode:��ʼ��ָ��ǰͷ�ڵ�*pHead
	ListNode* pNode = *pHead;
	 
	//3.ListNode* pPreNode:ָ���ϸ��ڵ�,��ʼ��Ϊ��
	ListNode* pPreNode = nullptr;

	//4.ѭ������
	while (pNode)
	{
		//4.1.�½�һ���ڵ�pNext��ָ���¸��ڵ�
		ListNode* pNext = pNode->m_pNext;

		//4.2 ���ñ�ǣ�pNode�ڵ��Ƿ���Ҫɾ��
		bool needDetele = false;

		//4.3 ����¸��ڵ�pNext��Ϊ�գ���pNode�ڵ�ֵ���¸��ڵ�pNext��ֵ��ͬ��pNode�ڵ����Ҫɾ��
		if (pNext!=nullptr && pNext->m_nValue == pNode->m_nValue)
			needDetele = true;
		   
		//4.4 �������Ҫɾ�����ͱ�����һ��
		if (!needDetele)
		{
			//4.4.1 �ϸ��ڵ�pPreNode��Ϊ��ǰ�ڵ�pNode 
			pPreNode = pNode;

			//4.4.2 ��ǰ�ڵ�pNode��Ϊ�¸��ڵ�pNext
			pNode = pNext;
		/*	pNode->m_nValue = pNext->m_nValue;
			pNode->m_pNext = pNext->m_pNext;*/
		}
 
		//4.5 ���򣬿�ʼɾ��
		else
		{
			//4.5.1 ��¼pNodeֵ
			int value = pNode->m_nValue;

			//4.5.2 ����Ҫɾ���Ľڵ����toBeDeleted����ʼ��Ϊ�ýڵ�
			ListNode* toBeDeleted = pNode; 
	 
			//4.5.3 ѭ�����������toBeDeleted�ڵ㲻Ϊ�գ��ҵ�����һ���ڵ㣬�ͽ�toBeDeletedɾ����
			while (toBeDeleted&&value == toBeDeleted->m_nValue)
			{
				//4.5.3.1 pNextָ��toBeDeleted�¸��ڵ�
				pNext = toBeDeleted->m_pNext;

				//4.5.3.2 ɾ��toBeDeleted�ڵ�
				delete toBeDeleted;
				toBeDeleted = nullptr;

				//4.5.3.3 toBeDeleted�ڵ㸳ֵΪ�¸��ڵ�pNext
				toBeDeleted = pNext; 
			} 

			//4.5.4 ���ɾ������ͷ�ڵ�,��pPreNodeΪ�գ���ͷ�ڵ��Ϊ�¸��ڵ�
			if (!pPreNode)
				*pHead = pNext;

			//4.5.5 ���򣬽�pPreNode���¸��ڵ�����Ϊ�¸��ڵ�pNext
			else
				pPreNode->m_pNext = pNext;

			//4.5.6 ��ǰ�ڵ�pNode��Ϊ�¸��ڵ�pNext
			pNode = pNext;
		}	
	}
}

// ====================���Դ���====================
void Test(char* testName, ListNode** pHead, int* expectedValues, int expectedLength)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    DeleteDuplication(pHead);

    int index = 0;
    ListNode* pNode = *pHead;
    while(pNode != nullptr && index < expectedLength)
    {
        if(pNode->m_nValue != expectedValues[index])
            break;

        pNode = pNode->m_pNext;
        index++;
    }

    if(pNode == nullptr && index == expectedLength)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// ĳЩ������ظ���
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 5 };
    Test("Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// û���ظ��Ľ��
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 3, 4, 5, 6, 7 };
    Test("Test2", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// ����һ�����֮���������н���ֵ����ͬ
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2 };
    Test("Test3", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// ���н���ֵ����ͬ
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    Test("Test4", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// ���н�㶼�ɶԳ���
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(2);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(3);
    ListNode* pNode7 = CreateListNode(4);
    ListNode* pNode8 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    Test("Test5", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// �����������֮��������㶼�ɶԳ���
void Test6()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);
    ListNode* pNode8 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2, 4 };
    Test("Test6", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// ������ֻ���������ظ��Ľ��
void Test7()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2 };
    Test("Test7", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// �����ֻ��һ�����
void Test8()
{
    ListNode* pNode1 = CreateListNode(1);

    ConnectListNodes(pNode1, nullptr);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1 };
    Test("Test8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// �����ֻ�������ظ��Ľ��
void Test9()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    Test("Test9", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// ������
void Test10()
{
    ListNode* pHead = nullptr;

    Test("Test10", &pHead, nullptr, 0);
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
    Test8();
    Test9();
    Test10();

	system("pause");
    return 0;
}
