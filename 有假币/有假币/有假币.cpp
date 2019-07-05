#include<iostream>
using namespace std;
int main()
{
	int N;
	while (cin >> N && N)
	{
		int ans = 0;
		long long sum = 1;
		while (sum < N)
		{
			sum *= 3;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
