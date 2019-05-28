//����ģʽʵ��

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

/*

//����ģʽʵ��
class Singleton {
public:
	static Singleton* GetInstance() {
		return &_instance;
	}
private:
	//���� �������� ��ֵ ˽�л�
	Singleton() {};
	//��ֹ������ֵ
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	//����һ�����������ָ��
	static Singleton _instance;
};

Singleton Singleton::_instance;

*/

//����ģʽʵ��

class Singleton {
public:
	static Singleton* GetInstance() {
		//����ж��Ƿ�ֹ��μ�������CPUƵ���л�
		if (_instance == nullptr) {
			_mutex.lock();
			//�ڲ��ж��Ǳ�ֻ֤ʵ����һ������
			if (_instance == nullptr) {
				_instance = new Singleton();
			}
			_mutex.unlock();
		}
		return _instance;
	}
	// ʵ��һ����Ƕ����������
	class CGarbo {
	public:
		~CGarbo() {
			if (Singleton::_instance)
				delete Singleton::_instance;
		}
	};
	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
private:
	//���� �������� ��ֵ ˽�л�
	Singleton() {};
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	static mutex _mutex;
	static Singleton* _instance;
};

Singleton* Singleton::_instance = nullptr;
mutex Singleton::_mutex;
Singleton::CGarbo Garbo;

void fun(int n) {
	cout << Singleton::GetInstance() << endl;
}

int main(void) {

	thread t1(fun, 10);
	thread t2(fun, 10);

	t1.join();
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	system("pause");
	return 0;
}