#include <iostream>

//����һ�������壬��Ϊ�������Ա����һ���ַ�ռ�
int check1() {
	typedef union Test {
		int a;
		char c;
	}Test;
	Test t;
	t.a = 1;
	return t.c == 1;
}

//ֱ������ָ��Ƚ�
int check2() {
	int a = 0x11223344;
	char* p = (char*)&a;
	if (*p == 0x11) {
		std::cout << "����ֽ���" << std::endl;
	}
	else {
		std::cout << "С���ֽ���" << std::endl;
	}
	return 0;
}

int main(void) {
	
	std::cout << "���������巽ʽ�жϽ�����£�" << std::endl;
	if (check1() == 1) {
		std::cout << "С���ֽ���" << std::endl;
	}
	else {
		std::cout << "����ֽ���" << std::endl;
	}
	std::cout << "����ָ�뷽ʽ�жϽ�����£�" << std::endl;
	check2();
	system("pause");
	return 0;
}