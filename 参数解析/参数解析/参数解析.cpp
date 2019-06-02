//在命令行输入如下命令
// xcopy /s c:\ d:\
//解析规则
// 参数分隔为空格
// “”包含的为一个参数
// 参数不定长

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {

	string s;
	while (getline(cin, s)) {
		vector<string> v;
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			
			if (s[i] != ' ') {
				tmp += s[i];
			}
			else if(s[i]==' '){
				v.push_back(tmp);
				tmp = "";
			}
		}
		v.push_back(tmp);
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << endl;
		}
	}

	system("pause");
	return 0;
}
