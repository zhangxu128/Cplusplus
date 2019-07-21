//��Ŀ����
//ţţ׼���μ�ѧУ��֯�Ĵ���, ����ǰţţ׼����������װ��һЩ��ʳ, ţţ�ı�������Ϊw��
//ţţ����һ����n����ʳ, ��i����ʳ���Ϊv[i]��
//ţţ��֪������������������������������, ��һ���ж�������ʳ�ŷ�(�����Ϊ0Ҳ��һ�ַŷ�)��
//�������� :
//�����������
//��һ��Ϊ����������n��w(1 <= n <= 30, 1 <= w <= 2 * 10 ^ 9), ��ʾ��ʳ�������ͱ�����������
//�ڶ���n��������v[i](0 <= v[i] <= 10 ^ 9), ��ʾÿ����ʳ�������
//������� :
//���һ��������, ��ʾţţһ���ж�������ʳ�ŷ���
//ʾ��1
//����
//
//����
//3 10
//1 2 4
//���
//
//����
//8
//˵��
//
//������ʳ�����С��10, ����ÿ����ʳ�з���Ͳ��������������һ����2 * 2 * 2 = 8�������



//��������1

//F[i][j] ������Ϊj��ʱ�򣬿��Է���ǰi����Ʒ������ֵ
// F[i][j] :  w[i] > j  F[i-1][j]
//                           //������  //�ڳ��ռ䣬������Ʒ     
//            w[i] <= j, max(F[i-1][j],F[i-1][j-w[i]+v[i]])

//��ʼ״̬  F[0][j] = 0  F[i][0] = 0;  ��F[n][m]


//��������2
//���У���ʾ��i�����뻹�ǲ����룬��state(i, w)��ʾi����ʳ���뱳��С�ڵ���W�ĸ�������state(i, w)�ֽ⣬���Էֽ�Ϊ���������
//1���ǵ�i��������ʱ��ǰi - 1����ʳ���뱳��С�ڵ���W�ĸ�����state(i - 1, w)��
//2�����ڵ�i�����������£�ǰi - 1����ʳ���뱳�����С�ڵ���W - v[i]�ĸ�����state(i - 1, w - v[i]);
//��               state(i, w) = state(i - 1, w) + state(i - 1, w - v[i])
//�߽�������i = 1ʱ��state(1, w1) ��ʱ���w1 > 0 ��v[1] <= w1, state(1, w1) = 2, ���пɷ���Ͳ��������֣�
//i = 1 ʱ��swate(1, w1)��ʱ���w1 > 0��v[1] > w1, state(1, w1) = 1, ��ֻ�в�����һ�֣�
//���state(i, w)�г���w <= 0, ��state(i, w) = 0;

#include<iostream>
#include <vector>


using namespace std;
long long sum = 0;
void bag(int count, long long weight, int arr[], int pos, const int w, const int n)
{
	if (weight > w) return;
	if (pos > n || pos < 0) return;
	if (pos == n)
	{
		sum++;
	}
	bag(++count, weight + arr[pos], arr, pos + 1, w, n);
	bag(count, weight, arr, pos + 1, w, n);
}

int main()
{
	int n;
	long long w;
	cin >> n >> w;
	int* arr = new int[n];
	long long count = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		count += arr[i];
	}
	if (count <= w)
	{
		sum = (pow(2, n));
		cout << sum;
		return 0;
	}
	bag(0, 0, arr, 0, w, n);
	cout << sum;
	system("pause");
	return 0;
}