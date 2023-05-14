#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using u64 = unsigned long long;

int main() {
    u64 n;
    cin >> n;
    vector<u64> a,b,c;

    for(auto i=0;i<n;i++) {
        u64 tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for(auto i=0;i<n;i++) {
        u64 tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    for(auto i=0;i<n;i++) {
        u64 tmp;
        cin >> tmp;
        c.push_back(tmp);
    }

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    u64 count = 0;
    for(auto i=0;i<n;i++) {
        // lower bound is <=
        // lb number is how many on the left
        int a_num = lower_bound(a.begin(), a.end(), b.at(i)) - a.begin();
        // cout << a_num << endl;

        // upper bound is > 
        // (n - ub) = how many above key value
        int c_num = upper_bound(c.begin(), c.end(), b.at(i)) - c.begin();
        // cout << c_num << endl;
        count += a_num * (n - c_num);
    }
    cout << count << endl;
}
