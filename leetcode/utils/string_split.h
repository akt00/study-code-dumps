#pragma once

vector<string> split(string s, const char delim){
	vector<string> list;
	while (true) {
		auto pos = s.find(delim);
		if (pos == string::npos) {
			list.push_back(s);
			return list;
		}

		list.push_back(s.substr(0, pos));
		s.erase(0, pos + 1);
	}
}
