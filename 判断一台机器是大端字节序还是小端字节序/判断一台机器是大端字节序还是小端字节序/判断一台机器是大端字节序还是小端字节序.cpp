#include <iostream>

//定义一个联合体，因为联合体成员共用一块地址空间
int check1() {
	typedef union Test {
		int a;
		char c;
	}Test;
	Test t;
	t.a = 1;
	return t.c == 1;
}

//直接利用指针比较
int check2() {
	int a = 0x11223344;
	char* p = (char*)&a;
	if (*p == 0x11) {
		std::cout << "大端字节序" << std::endl;
	}
	else {
		std::cout << "小端字节序" << std::endl;
	}
	return 0;
}

int main(void) {
	
	std::cout << "利用联合体方式判断结果如下：" << std::endl;
	if (check1() == 1) {
		std::cout << "小端字节序" << std::endl;
	}
	else {
		std::cout << "大端字节序" << std::endl;
	}
	std::cout << "利用指针方式判断结果如下：" << std::endl;
	check2();
	system("pause");
	return 0;
}