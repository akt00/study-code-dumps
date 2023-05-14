// calculate mod on positive and negative integers
int mod(int arg, int n) {
	if (arg < 0) {
		while (arg < 0) arg += n;
		return arg;
	}
	else return arg % n;
}

// parser: 1111 -> {1, 1, 1, 1}
void ParseConsecutiveInt(vector<int>& row, int input) {

	int count = 1;
	while (true) {
		int val = input % 10;
		row[row.size() - count] = val;
		input /= 10;
		count++;
		if (input <= 0) return;
	}
}

