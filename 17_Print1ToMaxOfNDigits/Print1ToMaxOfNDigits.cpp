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

// ������17����ӡ1������nλ��
// ��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
// ��ӡ��1��2��3һֱ������3λ����999��

#include <cstdio>
#include <stdio.h>
#include <memory>

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================����һ====================
void Print1ToMaxOfNDigits_1(int n)
{
	//1.���С�ڵ���0��ֱ�ӷ���
    if (n <= 0)
        return;
	//2.�������ַ��������ʾ���·���һ��n+1���ȵ��ַ������飬���һλ��Ž�����'\0'
    char *number = new char[n + 1];
	//3.memset��ʼ��ǰnλ��Ϊ0
    memset(number, '0', n);
	//4.���������һλ��ֵ'\0'
    number[n] = '\0';


	//5.�ظ�ִ�е����ַ�����������ӡ��ֱ���ַ�������Nλ��ʱ��ֹͣ��ӡ
    while (!Increment(number))
    {
		//5.1 ��ӡ�ַ���������ǰ��Ϊ0��������ӡ��
        PrintNumber(number);
    }
	//6.�ͷ��ַ��������ڴ档
    delete[]number;
}

// �ַ���number��ʾһ�����֣��� number������1
// ������ӷ�������򷵻�true������Ϊfalse
bool Increment(char* number)
{
	//1.bool��־�Ƿ��������ʼ��false
    bool isOverflow = false;
	//2.int ��λ
	int nTakeOver = 0;
	//3.��¼number�ĸ�������ȥ������
    int nLength = strlen(number);

	//4.�ӷ����ѭ���������ַ����Ӻ���ǰѭ������������:���λ�ﵽ10��break
    for (int i = nLength - 1; i >= 0; i--)
    {
		//4.1 nSum=�ַ���iλ����ֵ+�Ƿ��λ
        int nSum = number[i] - '0' + nTakeOver;

		//4.2 iΪ���һλ���͸�λ��ֵ++��ǰ���ַ�������
        if (i == nLength - 1)
            nSum++;

		//4.3 ������λ�õ���ֵ�ﵽ��10��˵���ý�λ��
		if (nSum >= 10)
		{
			//4.3.1 ������λ�øպ������λ���Ͳ����ٽ�λ���ͻ����������bool���Ϊ�档��ʱ���ٴ�ӡ��
			if (i == 0)
			{
				isOverflow = true; break;
			}
			//4.3.2 ������λ�ò������λ���ͽ�һλ 
            else
            {
				//4.3.2.1 ����ֵ��Ϊ0(nSum-10)
                nSum -= 10;
				//4.3.2.2 ����λ��Ϊ1�����ӵ���λ��ȥ
                nTakeOver = 1;
				//4.3.2.3 ����һλ��Ϊ0
                number[i] = '0' + nSum;
            }
        }
		//4.4 ���û�е���10������ֵ+'0'����������[i]�У�������ѭ����ʼ��ӡ��
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }
	//5.�����Ƿ����ֵbool
    return isOverflow;
}

// ====================������====================
void Print1ToMaxOfNDigits_2(int n)
{
	//1.���λ��С�ڵ���0���Ͳ���ӡ
	if (n <= 0)
		return;
	//2.���䳤��ΪN+1���ַ�������ָ��new char[n+1],����ĩλ��ֵ'\0'������
	char* number = new char[n + 1];
	number[n] = '\0';

	//3.����index=0��0-9��ѭ��
	for (int i = 0; i < 10; ++i)
	{
		//3.1 ����[0]��ֵi+'0'
		number[0] = i + '0';
		//3.2 ��ʼ���õݹ麯������index=0��ʼ������������һλ
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	//4.�ͷŵ�����ָ��delete[]
	delete[] number;
}

//�ݹ��ӡ����void���������ַ�������ָ��char*,����int,����λ��int,��������ӡ����PrintNumber(number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
	//1.�ݹ����������������õ������һλ���ʹ�ӡ���ַ���
	if (index == length - 1)
	{
		//1.1 ִ�й�������PrintNumber(number);
		PrintNumber(number);
		//1.2 ����
		return;
	}

	//2. ����index+1��0-9��ѭ��
	for (int i = 0; i < 10; ++i)
	{
		//2.1 ����[index+1]��ֵi+'0'
		number[index + 1] = i + '0';

		//2.2 ʹ�õݹ�������һλ������index+1
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}



// ====================��������====================
// �ַ���number��ʾһ�����֣����������ɸ�0��ͷ
// ��ӡ��������֣������Կ�ͷ��0
void PrintNumber(char* number)
{
	//1.bool��ǵ�һ�����Ƿ�Ϊ0��Ĭ��Ϊ0
    bool isBeginning0 = true;
	//2.����ĳ���,��nλ��������'\0'
    int nLength = strlen(number);
	//3.������[0]��ʼ��ӡ��ѭ��
    for (int i = 0; i < nLength; ++i)
    {
		//3.1 �жϸ�λ�Ƿ�Ϊ�㣺�����ǰbool���Ϊtrue,����һλΪ0���ж���һλ�Ƿ�Ϊ0���������0������bool��Ǹ�Ϊfalse��
        //if (isBeginning0 && number[i] != '0')
        //    isBeginning0 = false;
		if (isBeginning0)
			isBeginning0 = number[i] != '0' ? false:true;
		
		//3.2 �����λ��Ϊ0���Ϳ�ʼ��ӡ
        if (!isBeginning0)
        {
            printf("%c", number[i]);
        }
    }

    printf("\t");
}

// ====================���Դ���====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);
	printf("\n Solution 1:\n", n);
    Print1ToMaxOfNDigits_1(n);
	printf("\n Solution 2:\n", n);
    Print1ToMaxOfNDigits_2(n);

    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

	system("pause");
    return 0;
}

