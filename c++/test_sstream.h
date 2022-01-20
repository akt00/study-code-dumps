#ifndef TEST_SSTREAM
#define TEST_SSTREAM

#include<string>
#include<iostream>
#include<sstream>


class test {
private:
	int in;
	std::string str;
public:
	test() { in = 0; str = ""; }
	test(int i, std::string s) {
		in = i;
		str = s;
	}
	void set(int x, std::string s) { in = x; str = s; }

	std::string toString() const {
		std::ostringstream s;
		s << "int = " << in << std::endl;
		s << "string = " << str << std::endl;
		return s.str();
	}
};


std::istream& operator>>(std::istream& s, test& x) {
	int i;
	std::string st;
	s >> i >> st;
	x.set(i, st);
	return s;
}


std::ostream& operator<<(std::ostream& s, test& x) {
	return s << x.toString();
}


void test_sstreams() {
	test t;
	std::string end;
	do {
		std::cout << "t(int, string) = ";
		std::cin >> t;
		std::cout << t << std::endl;
		std::cout << "do you want to end? yes/no ";
		std::cin >> end;
	} while (end != "yes");;
}

#endif