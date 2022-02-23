#ifndef TEST_ALLOCATOR
#define TEST_ALLOCATOR

#include<iostream>
#include<memory>

class obj {
public:
	obj() {
		std::cout << "obj constructed...\n";
	}
	~obj() {
		std::cout << "obj destoryed...\n";
	}
};

void test_allocator() {

	int* ptr = new int{ 9 };
	std::cout << "ptr = " << ptr << " &ptr = " << &ptr << std::endl;
	delete ptr; // destroies and deallocates the object
	std::cout << "delete ptr = " << ptr << " &ptr = " << &ptr << std::endl;


	std::allocator<obj> alloc;
	std::cout << typeid(alloc).name() << std::endl;

	// decltype(std::allocator<int>)::value_type n = 19; // int

	using trait = std::allocator_traits<decltype(alloc)>;
	// allocates the memory
	auto *atr = trait::allocate(alloc, 1);
	// constructs the object
	trait::construct(alloc, atr);

	std::cout << " atr = " << atr << " &atr = " << &atr << std::endl;
	trait::destroy(alloc, atr); // destroies the object
	std::cout << " atr = " << atr << " &atr = " << &atr << std::endl;
	trait::deallocate(alloc, atr, 1); // decallocates the memory space
	std::cout << " atr = " << atr << " &atr = " << &atr << std::endl;
}

#endif
