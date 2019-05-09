#include <iostream>

#define GETOFFSET(Test,m) (size_t) &( ( (Test*)0 )->m)

//首先将0强制类型转化为结构体指针类型s*，此时的零的类型就是 s*，
//那么其当然可以访问其成员m（通过(s*)0->m 的方式访问），那么此时再取这个变量的地址，
//即 & ((s*)0->m)，这个地址呢减去结构体的基地址就是我们要求的偏移量。结构体的基地址是什么呢，
//不就是(s*)0吗？那么(s*)0等于多少？不就是0嘛，所以这样就能取到每个成员的偏移地址了


struct Test {
	int i;
	char a;
	short b;
	double l;
};


int main() {
	
	size_t offset1 = (size_t)(&((Test*)0)->i);
	size_t offset2 = (size_t)(&((Test*)0)->a);
	size_t offset3 = (size_t)(&((Test*)0)->b);
	size_t offset4 = (size_t)(&((Test*)0)->l);


	std::cout << "offset i = " << offset1 << std::endl;
	std::cout << "offset a = " << offset2 << std::endl;
	std::cout << "offset b = " << offset3 << std::endl;
	std::cout << "offset l = " << offset4 << std::endl;

	std::cout << "宏定义获取偏移量" << GETOFFSET(Test, a) << std::endl;
	std::cout << "sizeof(Test) = " << sizeof(Test) << std::endl;
	
	system("pause");
	return 0;
}