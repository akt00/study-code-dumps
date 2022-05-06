#ifndef TEST_IF_CONSTEXPR
#define TEST_IF_CONSTEXPR
#include<vector>


// dynamically determines the return type
template<typename T, typename U>
T generate_array(int size) {
	std::srand(static_cast<unsigned int>(std::time(0)));
	// if constexpr enables dynamic return type by pruning if branches
	if constexpr (std::is_same < T, std::vector<U> >::value) {
		std::vector<U> tmp;
		for (auto i = 0; i < size; i++) {
			U value = static_cast<U>(rand() % 10000 / 10.0);
			tmp.push_back(value);
		}
		return tmp;
	}
	else {
		std::unique_ptr<U[]> tmp(new U[size]{ 0 });
		for (auto i = 0; i < size; i++) {
			U value = static_cast<U>(rand() % 10000 / 10.0);
			tmp[i] = value;
		}
		return tmp;
	}
}

#endif
