#include<iostream>
using namespace std;

//����һ�������� num����дһ����������� num ��һ����ȫƽ�������򷵻� True�����򷵻� False��
//˵������Ҫʹ���κ����õĿ⺯������  sqrt��
//ʾ�� 1��
//���룺16
//�����True
//ʾ�� 2��
//���룺14
//�����False

bool isPerfectSquare(int num) {
	/*if (num < 0) {
		return false;
	}
	if (num == 1 || num == 0) {
		return true;
	}
	for (int i = 2; i <= num / 2; i++) {
		
		if ((i * i) == num) {
			return true;
		}
	}
	return false;*/   //��ʱ ����
	//����һ�ַ�����ȫƽ�����ض���ǰn�������ĺͣ����˷������ܻ�Խ�磬�������������Χ��
	//���ֲ���
	if (num <= 0) return false;
	int left = 0, right = num;    
	while (left < right) {          
		int mid = (left + right + 1ll) / 2;      
		if (mid <= num / mid)
			left = mid;
		else
			right = mid - 1;
	}
	if (left * left == num)
		return true;
	else
		return false;

}

int main()
{
	int num;
	cin >> num;
	//cout << 1ll << endl;
	cout << isPerfectSquare(num) << endl;
	system("pause");
	return 0;
}