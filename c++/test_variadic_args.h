#ifndef TEST_VARIADIC_ARGS
#define TEST_VARIADIC_ARGS
#include<iostream>
#include<cstdarg>


void variadic_ints(int args...) {
	va_list vlist;
	va_start(vlist, args);
	while (args != NULL) {
		std::cout << args << std::endl;
		args = va_arg(vlist, int);
	}
	va_end(vlist);
}


void variadic_char(const char* args...) {
	va_list vlist;
	va_start(vlist, args);
	auto arg = args;
	while (*arg != '\0') {
		std::cout << arg << std::endl;
		arg = va_arg(vlist, const char*);
	}
	va_end(vlist);
}



test_variadic_args() {
	variadic_ints(1, 2, 3, 4, 5, NULL);
	variadic_char("test", "hello", "world", "\0");
}

#endif
