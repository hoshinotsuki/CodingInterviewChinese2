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

// ������20����ʾ��ֵ���ַ���
// ��Ŀ����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬
// �ַ�����+100������5e2������-123������3.1416������-1E-16������ʾ��ֵ������12e����
// ��1a3.14������1.2.3������+-5������12e+5.4��������

#include <stdio.h>
#include <stdlib.h>

bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);
//
//// ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ������A��C����
//// �����������������ţ�Ҳ����û�У�����B��һ���޷�������
//bool isNumeric(const char* str)
//{
//    if(str == nullptr)
//        return false;
//
//    bool numeric = scanInteger(&str);
//
//    // �������'.'�������������ֵ�С������
//    if(*str == '.')
//    {
//        ++str;
//
//        // ����һ�д�����||��ԭ��
//        // 1. С������û���������֣�����.123����0.123��
//        // 2. С����������û�����֣�����233.����233.0��
//        // 3. ��ȻС����ǰ��ͺ�����������֣�����233.666
//        numeric = scanUnsignedInteger(&str) || numeric;
//    }
//
//    // �������'e'����'E'�����������ŵ������ֵ�ָ������
//    if(*str == 'e' || *str == 'E')
//    {
//        ++str;
//
//        // ����һ�д�����&&��ԭ��
//        // 1. ��e��Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣�����.e1��e1��
//        // 2. ��e��E����û������ʱ�������ַ������ܱ�ʾ���֣�����12e��12e+5.4
//        numeric = numeric && scanInteger(&str);
//    }
//
//    return numeric && *str == '\0';
//}
//
//bool scanUnsignedInteger(const char** str)
//{
//    const char* before = *str;
//    while(**str != '\0' && **str >= '0' && **str <= '9')
//        ++(*str);
//
//    // ��str�д�������0-9������ʱ������true
//    return *str > before;
//}
//
//// �����ĸ�ʽ������[+|-]B��ʾ, ����BΪ�޷�������
//bool scanInteger(const char** str)
//{
//    if(**str == '+' || **str == '-')
//        ++(*str);
//    return scanUnsignedInteger(str);
//}
//



                       
// �����ĸ�ʽ������[+|-]B��ʾ, ����BΪ�޷�������
bool scanInteger(const char** str) 
{
	//1.���ǰ����[+|-]�ţ�������һλ
	if (**str == '+' || **str == '-')
		(*str)++;//ע������(*str) Ҫ������ ++��*���ȼ��ߡ�

	//2.����������ɨ��
	return scanUnsignedInteger(str);
}

bool scanUnsignedInteger(const char** str)
{
	//1.����beforeָ�룬ָ��str��һ���ַ�
	const char* before = *str;
	//2.���*str��Ϊ�գ��������ֵĻ���������һ���ַ�
	while (*str&&**str >= '0'&&**str <= '9')
		(*str)++;
	//3.����������ַ��Ļ����ͷ�����,���򷵻ؼ�
	return before < *str ? true : false;
}

// ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ������A��C����
// �����������������ţ�Ҳ����û�У�����B��һ���޷�������
bool isNumeric(const char* str)
{
	//1.���Ϊ��
	if (!str)
		return false;

	//2.�жϵ�һ���ַ��Ƿ�����ֵ��A  
	bool numeric = scanInteger(&str);

	//3.�������С���� . ��||,��ΪС���������������1.1/0.1/1.0
	if (*str == '.')
	{
		//3.1 str++��Ϊ��ֵ����ΪҪȡ��ַ
		str++;
		//3.2 ����return ����numeric��ֵ
		numeric= scanUnsignedInteger(&str) || numeric  ;//ϸ�ڣ���ɨ��С��λB���Ƿ�Ϊunsigned����Ϊ���numeric==ture�Ͳ���ɨ��С��λ��
	}

	//4.�������ָ��e|E ,��&&����Ϊָ��ǰ����붼Ҫ�����֣� e2,1e�Ǵ��
	if (*str == 'e' || *str == 'E')
	{
		str++;
		numeric= numeric&&scanInteger(&str);
	}

	//5.�����Ƿ�Ϊ��ֵnumeric,���Ѿ�ɨ�赽��'\0'
	return numeric&&*str=='\0';
}


// ====================���Դ���====================
void Test(const char* testName, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    Test("Test21", nullptr, false);
	system("pause");

    return 0;
}
