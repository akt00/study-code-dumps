#pragma once

void replace_all(string& s, const string& from, const string& to) {
	
	unsigned size = from.size();
	unsigned pos;
	while ((pos = s.find(from)) != (unsigned) string::npos) {
		s.replace(pos, size, to);
	}
}
