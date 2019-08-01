//��Ŀ����
//�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
//·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
//���һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ�
//���� a b c e s f c s a d e e ������3 X 4 �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·����
//��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
private:

	bool isPath(char *matrix, vector<char> flags, char* str, int x, int y, int rows, int cols)
	{
		if (x < 0 || x >= rows || y < 0 || y >= cols) //Խ��ĵ�
			return false;

		if (matrix[x*cols + y] == *str  &&  flags[x*cols + y] == 0)
		{
			flags[x*cols + y] = 1;

			if (*(str + 1) == 0)  // �ַ�����β�ˣ����һ������ģ�
				return true;

			bool condition = isPath(matrix, flags, (str + 1), x, y - 1, rows, cols) ||
				isPath(matrix, flags, (str + 1), x - 1, y, rows, cols) ||
				isPath(matrix, flags, (str + 1), x, y + 1, rows, cols) ||
				isPath(matrix, flags, (str + 1), x + 1, y, rows, cols);
			if (condition == false)
				flags[x*cols + y] = 0;
			return condition;
		}
		else
			return false;




	}
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{

		vector<char> flags(rows*cols, 0);
		bool condition = false;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
			{
				condition = (condition || isPath(matrix, flags, str, i, j, rows, cols));
			}
		return condition;
	}

};

int main(void) {

	int row = 3;
	int col = 4;
	char* matrix = (char*)"abcesfcsadee";
	char* str = (char*)"bcced";
	Solution s;
	cout << s.hasPath(matrix, row, col, str) << endl;

	system("pause");
	return 0;
}