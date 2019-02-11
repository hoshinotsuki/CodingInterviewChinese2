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

// ������13�������˵��˶���Χ
// ��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
// ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
// ����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
// �������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

#include <cstdio>
#include <stdlib.h>
#include <string.h>

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
int getDigitSum(int number);

//int movingCount(int threshold, int rows, int cols)
//{
//    if(threshold < 0 || rows <= 0 || cols <= 0)
//        return 0;
//
//    bool *visited = new bool[rows * cols];
//    for(int i = 0; i < rows * cols; ++i)
//        visited[i] = false;
//
//    int count = movingCountCore(threshold, rows, cols,
//        0, 0, visited);
//
//    delete[] visited;
//
//    return count;
//}
//
//int movingCountCore(int threshold, int rows, int cols, int row,
//    int col, bool* visited)
//{
//    int count = 0;
//    if(check(threshold, rows, cols, row, col, visited))
//    {
//        visited[row * cols + col] = true;
//
//        count = 1 + movingCountCore(threshold, rows, cols,
//            row - 1, col, visited)
//            + movingCountCore(threshold, rows, cols,
//                row, col - 1, visited)
//            + movingCountCore(threshold, rows, cols,
//                row + 1, col, visited)
//            + movingCountCore(threshold, rows, cols,
//                row, col + 1, visited);
//    }
//
//    return count;
//}
//
//bool check(int threshold, int rows, int cols, int row, int col,
//    bool* visited)
//{
//    if(row >= 0 && row < rows && col >= 0 && col < cols
//        && getDigitSum(row) + getDigitSum(col) <= threshold
//        && !visited[row* cols + col])
//        return true;
//
//    return false;
//}
//
//int getDigitSum(int number)
//{
//    int sum = 0;
//    while(number > 0)
//    {
//        sum += number % 10;
//        number /= 10;
//    }
//
//    return sum;
//}


 
	//1.��������int����������ֵint,��������int,��������int������ֵ������int
	int movingCount(int threshold, int rows, int cols)
	{
		//1.1�����ֵΪ�������󲻴��ڣ�����0
		if (threshold<0 || rows<0 || cols<0)
			return 0;

		//1.2������ʾ���bool����ʼ��
		bool* visited = new bool[rows*cols];
		memset(visited, 0, rows*cols);

		//1.3��ʼ������Ϊ0
		int count = 0;
		//1.4 ��(0,0)��ʼ����
		count = movingCountCore(threshold, rows, cols, 0, 0, visited);


		//���ؼ���
		return count;
	}


	//2.��������int ,��������ֵint,��������int,��������int����ǰ����int,��ǰ����int,���ʾ�������bool*,����ֵ������int
	int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
	{
		//2.1 ��ʼ����Ϊ0
		int count = 0;

		//2.2 �����λ����������
		if (check(threshold, rows, cols, row, col, visited))
		{
			//2.2.1 ���·��ʾ���
			visited[row*cols + col] = true;

			//2.2.2 �Ӹ�λ�õ��������ҿ�ʼ��Ϊ��������еݹ����,�����Ǽ����������ã���������Ҵ���·�����û�
			count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited) +//��
				movingCountCore(threshold, rows, cols, row + 1, col, visited) +//��
				movingCountCore(threshold, rows, cols, row, col - 1, visited) +//��
				movingCountCore(threshold, rows, cols, row, col + 1, visited);//��


		}
		//2.3 ���ؼ���
		return count;
	}

	//3.ƥ�亯��bool,����������ֵint,��������int,��������int����ǰ����int,��ǰ����int,���ʾ�������bool*,����ֵ���Ƿ��������� bool
	bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
	{
		//3.1 �����λ������������1.��Խ�硣2.��������ֵ��3.δ�����ʹ����򷵻��档
		if (row<rows&&col<cols&&col>=0 && row>=0 && !visited[col + cols*row] && getDigitSum(row) + getDigitSum(col) <= threshold)
			return true;
		//3.2 ���򷵻ؼ١�
		return false;
	}

	//4. ������λ֮�ͺ���int,����������int,����ֵ����λ֮��int��
	int getDigitSum(int num)
	{
		//4.1 ��ʼ����Ϊ֮��Ϊ0
		int sum = 0;

		//4.2 ѭ��
		while (num>0)
		{
			//4.2.1 ȡ�࣬�ȼӸ�λ��
			sum += num % 10;
			//4.2.2 ����10����һλ
			num /= 10;
		}

		//4.3 ����sum
		return sum;
	}

	 

// ====================���Դ���====================
void test(char* testName, int threshold, int rows, int cols, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


// ������ж���
void test0()
{
	test("Test0", 1, 2, 2, 3);
}

// ������ж���
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// ������ж���
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// ����ֻ��һ�У��������ܵ������з���
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// ����ֻ��һ�У��������ܵ������з���
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// ����ֻ��һ��һ��
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// ����ֻ��һ��һ��
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// �����˲��ܽ�������һ������
void test9()
{
    test("Test9", -10, 10, 10, 0);
}

int main(int agrc, char* argv[])
{
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	system("pause");
    return 0;
}
