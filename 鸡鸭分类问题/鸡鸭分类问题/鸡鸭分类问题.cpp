//��Ŀ����
//ũ����nֻ��Ѽ��Ϊһ�����飬���á�C����ʾ��Ѽ�á�D����ʾ������Ѽ����ʱ�����ì�ܡ���Ҫ�����ŵĶ�����е�����
//ʹ��Ѽ����һ�ߡ�ÿ�ε���ֻ�������ڵļ���Ѽ����λ�ã�������Ҫ������ɶ������������Ҫ�����������Ҫ�������ٴο���������������١�
//���磺CCDCC->CCCDC->CCCCD��������ʹ֮ǰ��������Ѽ���ڱ�Ϊһ����Ѽ���ڣ���Ҫ�����������Ρ�
//�������� :
//����һ������ΪN����ֻ����C��D�ķǿ��ַ�����
//������� :
//ʹ��������һ�Լ�Ѽ���ڣ����ٵĽ�������
//ʾ��1
//����
//CCDCC
//���
//2


#include <iostream>
#include <string>

using namespace std;

inline int getResult(string& line) {
	auto len = line.size();
	int count = 0;
	for (decltype(len) i = 0; i < len - 1; ++i) {
		for (decltype(len) j = 0; j < len - 1 - i; ++j) {
			if (line[j] > line[j + 1]) {
				++count;
				auto temp = line[j];
				line[j] = line[j + 1];
				line[j + 1] = temp;
			}
		}
	}
	return count;
}

int main() {
	string line;
	while (cin >> line) {
		auto res = getResult(line);
		cout << res << endl;
	}
	return 0;
}
