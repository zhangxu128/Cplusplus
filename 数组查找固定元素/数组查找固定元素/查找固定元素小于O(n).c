#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int find(int a[][3], int row, int rol, int x, int y, int key, int* rowx, int* roly)
{
	if (key == a[x][y])
	{
		*rowx = x;
		*roly = y;
		return 1;
	}
	else if (key > a[x][y])
	{
		return find(a, row, rol, ++x, y, key, rowx, roly);
	}
	else if (key < a[x][y])
	{
		return find(a, row, rol, x, --y, key, rowx, roly);
	}
	if (x >= row || y < 0)
	{
		return -1;
	}
	return 0;
}

int main()
{
	int a[][3] = { 1,2,3,4,5,6,7,8,9 };
	int key;
	int x = 0;
	int y = 0;
	int* rowx = &x;
	int* roly = &y;
	scanf("%d",&key);
	find(a,3 ,3, 0, 2 , key, rowx, roly);
	printf("%d,%d\n",x,y);
	system("pause");
	return 0;
}