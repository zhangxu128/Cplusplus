//���һ����򵥵�����ָ��
//����operator*��opertaor->��������ָ��һ������Ϊ

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

//ģ��ʵ��std::auto_ptr

template<class T>
class AutoPtr {
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{}
	~AutoPtr() {
		if (_ptr) 
			delete _ptr;
	}
	//��������  ��ֵ��Ҫ������Դת��
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