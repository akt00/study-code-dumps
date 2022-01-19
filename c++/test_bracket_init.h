#ifndef TEST_BRACKET_INIT
#define TEST_BRACKET_INIT

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

#endif