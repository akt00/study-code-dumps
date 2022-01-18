#include"test_template_class.h"

// explicit instantiation
template class Vec<int>;
template class Vec<double>;

template <typename T>
Vec<T>::Vec(int s) {
	this->size = s;
	vec.resize(s);
	srand(NULL(0));
	for (auto& i : vec) {
		i = static_cast<T>(rand() % 1000 / 10.0);
	}
}

template <typename T>
void Vec<T>::sort() {
	for (auto i = 0; i < vec.size(); i++) {
		T key = vec[i];
		auto j = i - 1;
		while (j > -1 && vec[j] > key) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

template<typename T>
void Vec<T>::show() {
	for (auto& i : vec) {
		std::cout << i << std::endl;
	}
}

template<typename T>
auto Vec<T>::search(T key) -> decltype(T{}){
	for (auto& i : vec) {
		if (key == i) return i;
	}
	return -1;
}
