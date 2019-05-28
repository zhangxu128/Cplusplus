//单例模式实现

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

/*

//饿汉模式实现
class Singleton {
public:
	static Singleton* GetInstance() {
		return &_instance;
	}
private:
	//构造 拷贝构造 赋值 私有化
	Singleton() {};
	//防止拷贝赋值
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	//定义一个单例对象的指针
	static Singleton _instance;
};

Singleton Singleton::_instance;

*/

//懒汉模式实现

class Singleton {
public:
	static Singleton* GetInstance() {
		//外层判断是防止多次加锁导致CPU频繁切换
		if (_instance == nullptr) {
			_mutex.lock();
			//内层判断是保证只实例化一个对象
			if (_instance == nullptr) {
				_instance = new Singleton();
			}
			_mutex.unlock();
		}
		return _instance;
	}
	// 实现一个内嵌垃圾回收类
	class CGarbo {
	public:
		~CGarbo() {
			if (Singleton::_instance)
				delete Singleton::_instance;
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:
	//构造 拷贝构造 赋值 私有化
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