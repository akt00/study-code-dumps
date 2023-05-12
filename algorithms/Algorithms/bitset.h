#ifndef ALGORITHM_CONTAINER_BITSET
#define ALGORITHM_CONTAINER_BITSET
#include <cassert>
#include <vector>


template<unsigned SIZE>
class Bitset {
public:
	using u64 = unsigned long long;

	Bitset() { _bitset = new u64[int(SIZE / 64) + 1]{}; }

	Bitset(const Bitset<SIZE>& other) {

		int max_index = (int)other.MaxSize() / 64;
		_bitset = new u64[max_index + 1]{};
		for (auto i = 0; i <= max_index; i++) {
			_bitset[i] = other._bitset[i];
		}
	}

	Bitset& operator=(const Bitset<SIZE>& other) {

		if (&other != this) {
			int max_index = (int)other.MaxSize() / 64;
			_bitset = new u64[max_index + 1]{};
			for (auto i = 0; i <= max_index; i++) {
				_bitset[i] = other._bitset[i];
			}
		}
	}

	~Bitset() {
		delete[] _bitset;
	}

	bool empty() const { return (size() == 0) ? true : false; }

	unsigned size() const {

		int max_index = SIZE / 64;
		int count = 0;
		for (auto i = 0; i <= max_index; i++) {
			u64 x = _bitset[i];
			while (x) {
				x &= x - 1;
				count++;
			}
		}
		return count;
	}

	unsigned MaxSize() const { return SIZE; }

	std::vector<int> GetElements() const {
		std::vector<int> elements;
		int max_index = SIZE / 64;
		for (auto i = 0; i <= max_index; i++) {
			for (auto j = 1; j <= 64; j++) {
				auto tmp = 1ULL << j - 1;
				if (tmp & _bitset[i]) elements.push_back(j + i * 64);
			}
		}
		return elements;
	}

	bool contains(int arg) const {
		int index = (int)arg / 64;
		int sift = arg % 64 - 1;
		if (_bitset[index] & (1ULL << sift)) return true;
		return false;
	}

	void add(int arg) {

		assert(arg > 0);
		assert(arg <= SIZE);
		int index = (int)arg / 64;
		u64 sift = arg - index * 64;
		u64 u = 1ULL << sift - 1;
		_bitset[index] |= u;
	}

	void remove(int arg) {

		assert(arg > 0);
		assert(arg <= SIZE);
		int index = (int)arg / 64;
		u64 sift = arg - index * 64;
		u64 u = 1ULL << sift - 1;
		_bitset[index] ^= u;
	}

	void Union(const Bitset& other) {

		int max_index = (int(this->MaxSize() / 64) < int(other.MaxSize() / 64)) ? int(this->MaxSize() / 64) : int(other.MaxSize() / 64);
		for (auto i = 0; i <= max_index; i++) {
			_bitset[i] |= other._bitset[i];
		}
	}

	void Disjunction(const Bitset& other) {

		int max_index = (int(this->MaxSize() / 64) < int(other.MaxSize() / 64)) ? int(this->MaxSize() / 64) : int(other.MaxSize() / 64);
		for (auto i = 0; i < max_index; i++) {
			_bitset[i] ^= other._bitset[i];
		}
	}

private:
	u64* _bitset;
};


#endif // ALGORITHM_CONTAINER_BITSET