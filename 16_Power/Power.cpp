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

// ������16����ֵ�������η�
// ��Ŀ��ʵ�ֺ���double Power(double base, int exponent)����base��exponent
// �η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

#include <iostream>
#include <stdio.h>
#include <cmath>
 

// bool g_InvalidInput = false;
 bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

//double Power(double base, int exponent)
//{
//    g_InvalidInput = false;
//
//    if (equal(base, 0.0) && exponent < 0)
//    {
//        g_InvalidInput = true;
//        return 0.0;
//    }
//
//    unsigned int absExponent = (unsigned int) (exponent);
//    if (exponent < 0)
//        absExponent = (unsigned int) (-exponent);
//
//    double result = PowerWithUnsignedExponent(base, absExponent);
//    if (exponent < 0)
//        result = 1.0 / result;
//
//    return result;
//}
//
///*
//double PowerWithUnsignedExponent(double base, unsigned int exponent)
//{
//    double result = 1.0;
//    
//    for (int i = 1; i <= exponent; ++i)
//        result *= base;
//
//    return result;
//}
//*/
//
//double PowerWithUnsignedExponent(double base, unsigned int exponent)
//{
//    if (exponent == 0)
//        return 1;
//    if (exponent == 1)
//        return base;
//
//    double result = PowerWithUnsignedExponent(base, exponent >> 1);
//    result *= result;
//    if ((exponent & 0x1) == 1)
//        result *= base;
//
//    return result;
//}
//
bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}
////////////////////
//�ҵ�
/////////////////////

////1.ȫ�ֱ�������쳣ֵ
 bool g_InvalidInput = false;
//
//double Power(double base, int exponent) {
//	//2.��ʼ��ȫ�ֱ���
//	g_InvalidInput = false;
//
//	//3.����������Ϊ0��ָ��Ϊ��������0�����쳣
//	if (base == 0.0 && exponent<0)
//	{
//		g_InvalidInput = true;
//		return 0;
//	}
//
//	//4.�����޷��ű������ָ���ľ���ֵ
//	unsigned int absExponent = (unsigned int)exponent;
//	if (exponent<0)
//	{
//		absExponent = -exponent;
//	}
//
//	//5.������ָ���ĺ���������double�ʹ���ָ���Ľ��
//	double result = PowerWithUnsignedExponent(base, absExponent);
//
//	//6.���ָ���Ǹ���������
//	if (exponent<0)
//		result = 1 / result;
//
//	//7.���ؽ��
//	return result;
//
//}
//
//
////��ָ���ĺ���double,����������double,ָ��unsigned int������ֵ�����double�������ָ���Ѿ�ȡ�˾���ֵ��������unsigned int��
//double PowerWithUnsignedExponent(double base,unsigned int exponent)
//{
//
//	//1.���ָ��Ϊ0������1
//	if (exponent == 0)
//		return 1;
//	//2.���ָ��Ϊ1�����ص���
//	if (exponent == 1)
//		return base;
//
//	//������ѧ֪ʶ��֪��
//	//���exponentΪż����result=base^(exponent/2)*base^(exponent/2)
//	//���exponentΪż����result=base^((exponent-1)/2)*base^((exponent-1)/2)*base
//	//3.ʹ�õݹ飬���Եõ�base^(exponent/2),��div2�Ľ����������һλ��>>1�����
//	double result = PowerWithUnsignedExponent(base, exponent >> 1);
//
//	//4.������ݹ麯���õ���div2�Ľ�����
//	result = result*result;
//
//	//5.�ж�ԭ����ָ������ż��,��������������ٳ���һ����������������λ������졣
//	if (exponent & 1 == 1)
//		result *= base;
//
//	//6.���ؽ��
//	return result;
//}

double Power(double base, int exponent) {
	long long p = abs((long long)exponent);
	double r = 1.0;
	while (p) {
		if (p & 1) r *= base;
		base *= base;
		p >>= 1;
	}
	return exponent < 0 ? 1 / r : r;
}

// ====================���Դ���====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
    // ������ָ����Ϊ����
    Test("Test1", 2, 3, 8, false);

    // ����Ϊ������ָ��Ϊ����
    Test("Test2", -2, 3, -8, false);

    // ָ��Ϊ����
    Test("Test3", 2, -3, 0.125, false);

    // ָ��Ϊ0
    Test("Test4", 2, 0, 1, false);

    // ������ָ����Ϊ0
    Test("Test5", 0, 0, 1, false);

    // ����Ϊ0��ָ��Ϊ����
    Test("Test6", 0, 4, 0, false);

    // ����Ϊ0��ָ��Ϊ����
    Test("Test7", 0, -4, 0, true);

	system("pause");

    return 0;
}

