#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


inline double dist(int x1, int y1, int x2, int y2) {

    return (double)sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}


int main() {

    int n;
    cin >> n;
    vector<vector<int>> points;

    for (auto i = 0; i < n; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        points.push_back({x,y});
    }

    std::sort(points.begin(), points.end());

    double total_dist = 0;
    int count = 0;
    
    while (true) {
        count++;
        for (auto i = 0; i < points.size() - 1; i++) {
            total_dist += dist(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
        }
        if (next_permutation(points.begin(), points.end()) == false) break;
    }
    printf("%f", total_dist / count);
}

/*
#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	double sum = 0.00000000000;
	
	for (int i = 0; i < n; i++) {
		cin >> x.at(i) >> y.at(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += sqrt((x.at(i) - x.at(j)) * (x.at(i) - x.at(j)) + (y.at(i) - y.at(j)) * (y.at(i) - y.at(j)));
		}
	}
	printf("%f", sum / n);
}
*/
