//设计一个最简单的智能指针
//重载operator*和opertaor->，具有像指针一样的行为

template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr) 
		:_ptr(ptr)
	{}
	~SmartPtr() {
		if(_ptr)
			delete _ptr;
	}
	T& operator*() {
		return *_ptr;
	}
	T* operator->() {
		return _ptr;
	}
protected:
	T* _ptr;
};

//模拟实现std::auto_ptr

template<class T>
class AutoPtr {
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{}
	~AutoPtr() {
		if (_ptr) 
			delete _ptr;
	}
	//拷贝构造  赋值就要进行资源转移
	AutoPtr(AutoPtr<T>& ap) 
		:_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}

	AutoPtr<T>& operator=(AutoPtr<T>& ap){
		if (*this != ap) {
			if (_ptr)
				delete _ptr;

			_ptr = ap._ptr;
			ap.ptr = nullptr;
		}
		return *this;
	}

	T& operator*() {
		return *_ptr;
	}
	T* operator->() {
		return _ptr;
	}
};