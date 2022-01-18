#ifndef TEST_TEMPLATE_CLASS
#define TEST_TEMPLATE_CLASS

#include<iostream>
#include<vector>

// there are 3 ways to deal with link errors with template
//#1 write everything in header
//#2 write implementation in .xpp file and include the .xpp file from header (.cpp should be avoided to be included)
//#3 write implementation in .cpp file and do the explicit instantiation 

template<typename T>
class Vec {
private:
	std::vector<T> vec;
	int size;
public:
	Vec(int s);
	void sort();
	void show();
	auto search(T key) -> decltype(T{});
};


#endif