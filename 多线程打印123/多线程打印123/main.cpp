//我们提供了一个类：
//
//public class Foo {
//	public void one() { print("one"); }
//	public void two() { print("two"); }
//	public void three() { print("three"); }
//}
//三个不同的线程将会共用一个 Foo 实例。
//
//线程 A 将会调用 one() 方法
//线程 B 将会调用 two() 方法
//线程 C 将会调用 three() 方法
//请设计修改程序，以确保 two() 方法在 one() 方法之后被执行，three() 方法在 two() 方法之后被执行。
//	示例 1:
//	输入: [1, 2, 3]
//	输出 : "onetwothree"
//	解释 :
//	有三个线程会被异步启动。
//	输入[1, 2, 3] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 two() 方法，线程 C 将会调用 three() 方法。
//	正确的输出是 "onetwothree"。
//	示例 2 :
//	输入 : [1, 3, 2]
//	输出 : "onetwothree"
//	解释 :
//	输入[1, 3, 2] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 three() 方法，线程 C 将会调用 two() 方法。
//	正确的输出是 "onetwothree"。

#include <mutex>
#include <condition_variable>

class Foo {
public:
	Foo() {

	}

	void first(function<void()> printFirst) {

		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		std::lock_guard<std::mutex> lock(_mutex);
		one_ok = true;
		_cond.notify_all();
	}

	void second(function<void()> printSecond) {

		std::unique_lock<std::mutex> lock(_mutex);
		_cond.wait(lock, [&]() {
			return this->one_ok;
		});
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		two_ok = true;
		_cond.notify_all();
	}

	void third(function<void()> printThird) {

		std::unique_lock<std::mutex> lock(_mutex);
		_cond.wait(lock, [&]() {
			return _two_ok;
		});
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}

private:
	std::mutex _mutex;
	std::condition_variable _cond;
	bool one_ok;
	bool two_ok;
};