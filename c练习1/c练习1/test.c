#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//打印固定数字之间的素数 
void printPrime(int start, int end) {
	for (start; start <= end; start++) {
		int i = 2;
		for (; i < start; i++) {
		    if (start%i == 0) {
			   break;
			}
		}
		if (i == start) {
			printf("%d\t", start);
		}
	}
}

int main() {
	int start, end;
	scanf("%d %d", &start, &end);
	printPrime(start , end);
	system("pause");
	return 0;
}