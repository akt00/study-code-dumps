#ifndef TEST_INITIALIZER
#define TEST_INITIALIZER

class Foo {
private:
	int a;
	int b;
public:
	explicit Foo(int aa, int bb) {
		a = aa;
		b = bb;
	}
};

bool foo(int a, int b) {
	bool flag{ a == b };
	return flag;
}

#endif // TEST_INITIALIZER
