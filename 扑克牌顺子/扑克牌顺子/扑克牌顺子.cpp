//��Ŀ����
//LL���������ر��, ��Ϊ��ȥ����һ���˿���, ���������Ȼ��2������,
//2��С��(һ����ԭ����54��^_^)...��������г����5����, �����Լ�������,
//�����ܲ��ܳ鵽˳��, ����鵽�Ļ�, ������ȥ��������Ʊ, �ٺ٣���������A, ����3, 
//С��, ����, ��Ƭ5��, ��Oh My God!������˳��.....LL��������, ��������, 
//������\С�����Կ����κ�����, ����A����1, JΪ11, QΪ12, KΪ13�������5���ƾͿ��Ա��
//��1, 2, 3, 4, 5��(��С���ֱ���2��4), ��So Lucky!����LL����ȥ��������Ʊ���� ����, 
//Ҫ����ʹ�������ģ������Ĺ���, Ȼ���������LL��������Σ�
//����������˳�Ӿ����true����������false��Ϊ�˷������, �������Ϊ��С����0��

#include <iostream>
#include <string>
#include <vector>


using namespace std;

bool IsContinuous(vector<int> numbers) {

	if (numbers.empty()) return 0;
	int count[14] = { 0 };//��¼ÿ��Ԫ�س��ֵĴ���;��numbers�е�Ԫ����Ϊ�±�(���K,��Ӧ13)
	int len = numbers.size();
	int max = -1;
	int min = 14;

	for (int i = 0; i < len; ++i)
	{
		count[numbers[i]]++;
		if (numbers[i] == 0) continue;

		if (count[numbers[i]] > 1) return 0;

		if (numbers[i] > max) max = numbers[i];

		if (numbers[i] < min) min = numbers[i];

	}
	if (max - min < 5) return true;
	return false;
}
int main(void) {

	vector<int> v(5);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}
	cout << IsContinuous(v) << endl;
	system("pause");
	return 0;
}