#ifndef TEST_CASTING
#define TEST_CASTING

#include<iostream>
#include<cassert>

struct A {};
struct B : A {};


// const cast: changes the mutability of the object
// static_cast: implicit conversion where overloading possible, downcast or upcast though it's safer to use dynamic_cast
// dynamic_cast: used for polymorphism
// reinterpret_cast: change interepretation of the dtype
// type casting generates a rvalue
void test_casting() {

	// const_cast can not be used on const variable
	// const_cast is used to remove const-ness from const function or const pointer
	const int immutable = 777;
	std::cout << "immutable = " << immutable << " " << &immutable << std::endl;
	auto mut = const_cast<int*>(&immutable); // not allowed, undefined behavior
	std::cout << "mut = " << *mut << " " << mut << std::endl;


	A a;
	B b;
	std::cout <<"type a = " << typeid(a).name() << std::endl;

	auto ab = static_cast<B&>(a); // downcast requires a reference to the data type pointer
	auto ba = static_cast<A>(b); // upcast requires nothing
	std::cout << "type ab = " << typeid(ab).name() << std::endl;
	std::cout << "type ba = " << typeid(ba).name() << std::endl;

	// downcast with dynamic_cast only awllowed with polymophic class with virtual functions to store vtable
	// downcast is only allowed when the derived class implements virtual fucntions of the parent class
	auto ba_ptr = dynamic_cast<A*>(&b); // upcast allowed
	std::cout << "type ba_ptr = " << typeid(ba_ptr).name() << std::endl;
	// auto bab_ptr = dynamic_cast<B*>()
	// auto bab_ptr = dynamic_cast<B*>(&a); // downcast not allowed because no vtable

	int i = 99;
	void* v;
	v = &i;
	std::cout << "type v = " << typeid(v).name() << std::endl;
	// change the interpretation of data type in the memory
	auto vv = reinterpret_cast<int*>(v);
	std::cout << "type vv = " << typeid(vv).name() << std::endl;

}


#endif
