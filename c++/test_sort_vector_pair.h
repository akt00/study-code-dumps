void test_sort_vector_pair() {
	using ivec = vector<int>;
	using svec = vector<string>;

	ivec weights = { 40, 30, 99, 10 };
	svec names = { "alice", "bob", "claire", "michael" };

	vector< std::pair<int, string>> p;
	auto CompSec = [](const pair<int, string>& a, const pair<int, string>& b) {return (a.second < b.second); };
	for (auto i = 0; i < 4; i++) {
		p.push_back({ weights[i], names[i] });
	}
	
	std::sort(p.begin(), p.end(), CompSec);
	for (auto i : p) {
		cout << i.first << " " << i.second << endl;
	}
}
