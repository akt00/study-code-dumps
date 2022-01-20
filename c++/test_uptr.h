#ifndef TEST_UPTR
#define TEST_UPTR

#include<iostream>


class TestUptr {
private:
	std::unique_ptr<int> value;
public:
	TestUptr(int v) {
		value = std::make_unique<int>(v);
	}
	void show() {
		std::cout << "unique_ptr value = " << *value << std::endl;
	}
	void change() {
		*value = 666;
	}
	~TestUptr() {
		std::cout << "destructor activated" << std::endl;
	}
};


void test_func() {
	
	TestUptr t(999);
	t.change();
	t.show();
}

#endif