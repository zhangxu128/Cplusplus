#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
		给20元，可以多少汽水。
		编程实现。*/
	int price = 1;
	int juice_count = 0;       //  20   10   5  2  1 
	int sum_price = 20;      
	for (int i = 1; i <= sum_price; i++)
	{
		juice_count++;
		if (i % 2 == 0)
		{
			sum_price += 1;
		}
	}
	juice_count--;
	printf("%d\n",juice_count);
	system("pause");
	return 0;
}