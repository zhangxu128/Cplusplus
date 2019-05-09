#include <iostream>

#define GETOFFSET(Test,m) (size_t) &( ( (Test*)0 )->m)

//���Ƚ�0ǿ������ת��Ϊ�ṹ��ָ������s*����ʱ��������;��� s*��
//��ô�䵱Ȼ���Է������Աm��ͨ��(s*)0->m �ķ�ʽ���ʣ�����ô��ʱ��ȡ��������ĵ�ַ��
//�� & ((s*)0->m)�������ַ�ؼ�ȥ�ṹ��Ļ���ַ��������Ҫ���ƫ�������ṹ��Ļ���ַ��ʲô�أ�
//������(s*)0����ô(s*)0���ڶ��٣�������0�������������ȡ��ÿ����Ա��ƫ�Ƶ�ַ��


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

	std::cout << "�궨���ȡƫ����" << GETOFFSET(Test, a) << std::endl;
	std::cout << "sizeof(Test) = " << sizeof(Test) << std::endl;
	
	system("pause");
	return 0;
}