#ifndef ALGORITHM_UTILS
#define ALGORITHM_UTILS
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


namespace algorithm::utils {

	inline bool IsPrime(unsigned n) {

		unsigned n_sqrt = (unsigned)sqrt(n);
		for (unsigned i = 2; i <= n_sqrt; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}

	inline std::vector<unsigned> sieve_of_eratosthenes(unsigned n) {

		unsigned sqrt_n = (unsigned) sqrt(n);
		std::vector<unsigned> primes;
		bool *sieve = new bool[n + 1] {};
		unsigned i = 2;

		for (i; i <= sqrt_n; i++) {
			if (sieve[i] == false) {
				if (IsPrime(i) == true) {
					primes.push_back(i);
				}
				for (auto j = i; j <= n; j += i) {
					sieve[j] = true;
				}
			}
		}
		for (i; i <= n; i++) {
			if (sieve[i] == false) primes.push_back(i);
		}
		delete[] sieve;
		return primes;
	}

	// thrown an error occurs when accessing  file
	class FileAccessError : public std::exception {
	public:
		const char* what() const noexcept override {
			return "Failed to open the file\n";
		}
	};

	// extract the index for min value
	template<typename T>
	inline unsigned FindMinIndex(T array_list, unsigned size) {

		auto min = array_list[0];
		unsigned index = 0;
		for (unsigned i = 1; i < size; i++) {
			if (min > array_list[i]) {
				min = array_list[i];
				index = i;
			}
		}
		return index;
	}

	// extract the index for max value
	template<typename T>
	inline unsigned FindMaxIndex(T array_list, unsigned size) {

		auto max = array_list[0];
		unsigned index = 0;
		for (unsigned i = 1; i < size; i++) {
			if (max < array_list[i]) {
				max = array_list[i];
				index = i;
			}
		}
		return index;
	}

	// sequential search
	// returns the corresponding index with key, size if not found
	template<typename T, typename U>
	inline unsigned SequentialSearch(T array_list, unsigned size, U key) {

		for (unsigned i = 0; i < size; i++) {
			if (array_list[i] == key) return (unsigned)i;
		}
		return size;
	}

	// binary search
	template<typename T, typename U>
	inline unsigned BinarySearch(T array_list, unsigned size, U key) {
		
		unsigned left = 0;
		unsigned mid = size / 2;
		unsigned right = size - 1;
		while (left <= right) {
			if (array_list[mid] == key) return mid;
			(array_list[mid] < key) ? left = mid + 1 : right = mid;
			mid = (left + right) / 2;
		}
		return size;
	}

	template<typename T>
	inline std::vector<T> GenerateRandomArray(unsigned size=-1) {

		std::srand((unsigned)std::time(nullptr));
		std::vector<T> vec;
		(size == -1) ? vec.resize(std::rand()) : vec.resize(size);
		for (auto i = 0; i < vec.size(); i++) {
			vec[i] = static_cast<T>(std::rand() % RAND_MAX / 100.0);
		}
		return vec;
	}

	template<typename T>
	inline std::vector<T> GenerateSortedArray(unsigned size = -1) {

		std::vector<T> vec;
		(size == -1) ? vec.resize(std::rand()) : vec.resize(size);
		for (auto i = 0; i < vec.size(); i++) {
			vec[i] = static_cast<T>(i * 1000 / 100.0);
		}
		return vec;
	}

	// 1. check the order of the elements
	// 2. check the correctness of the elements
	template<typename T, typename U>
	inline bool ValidateSortedArray(T unsorted, T sorted, unsigned size, bool asc = true) {

		std::unordered_map<U, unsigned> map_unsorted;
		std::unordered_map<U, unsigned> map_sorted;
		for (unsigned i = 0; i < size; i++) {
			auto iter_u = map_unsorted.find(unsorted[i]);
			if (iter_u == map_unsorted.end()) map_unsorted.insert({ unsorted[i], 1 });
			else iter_u->second++;
			auto iter_s = map_sorted.find(sorted[i]);
			if (iter_s == map_sorted.end()) map_sorted.insert({ sorted[i], 1 });
			else iter_s->second++;
		}

		for (unsigned i = 0; i < size - 1; i++) {
			if (asc) {
				if (sorted[i] > sorted[i + 1]) return false;
			}
			else {
				if (sorted[i] < sorted[i + 1]) return false;
			}
		}

		for (auto iter_u : map_unsorted) {
			auto iter_s = map_sorted.find(iter_u.first);
			if (iter_s == map_sorted.end() || iter_s->second != iter_u.second) return false;
		}
		return true;
	}

	// inline to avoid multiple definitions
	// load a CSV file line by line
	inline std::vector<std::string> LoadCSV(const char* filepath) {
		
		std::fstream io;
		io.open(filepath, std::fstream::in);
		if (!io.is_open()) {
			std::cerr << "failed to open file at " << filepath << std::endl;
			throw FileAccessError();
		}
		
		std::vector<std::string> lines;
		while (!io.eof()) {
			std::string line;
			std::getline(io, line);
			lines.push_back(line);
		}
		io.close();
		return lines;
	}

	// parse the line in CSV
	// supported types: arithmetics & string
	template<typename T>
	inline std::vector<T> ParseLineCSV(const std::string& line) {

		std::vector<std::string> row_data_str;
		std::string value_str("");
		for (auto i : line) {
			if (i == ',') {
				row_data_str.push_back(value_str);
				value_str.clear();
			}
			else {
				value_str += i;
			}
		}
		row_data_str.push_back(value_str);

		if constexpr (std::is_arithmetic<T>::value) {
			std::vector<T> row_data;
			for (auto i : row_data_str) {
				row_data.push_back(static_cast<T>(std::stod(i)));
			}
			return row_data;
		}
		else return row_data_str;
	}
	
	// load the iris dataset
	using IRIS_DATASET = std::pair < std::vector<std::vector<float>>, std::vector<int>>;
	inline IRIS_DATASET LoadIris(const char* filepath="./data/iris.csv") {

		auto rows = LoadCSV(filepath);
		std::vector<std::vector<float>> features;
		std::vector<int> labels;
		for (auto i = 0; i < rows.size(); i++) {
			auto row_values = ParseLineCSV<float>(rows[i]);
			std::vector<float> feature;
			for (auto j = 0; j < row_values.size(); j++) {
				if (j == row_values.size() - 1) labels.push_back((int)row_values[j]);
				else feature.push_back((float)row_values[j]);
			}
			features.push_back(feature);
		}
		return { features, labels };
	}

	// transform vector: (150,4)->(4,150)
	template<typename T>
	using VEC_2D = std::vector<std::vector<T>>;
	template<typename T>
	inline VEC_2D<T> Transpose2dVector(const VEC_2D<T>& features) {
		
		VEC_2D<T> transposed;
		for (auto i = 0; i < features[0].size(); i++) {
			std::vector<T> row;
			for (auto j = 0; j < features.size(); j++) {
				row.push_back(features[j][i]);
			}
			transposed.push_back(row);
		}
		return transposed;
	}
}

#endif // ALGORITHM_UTILS