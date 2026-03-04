#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> times;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        times.push_back(t);
    }

    sort(times.begin(), times.end());

    int sum = 0;
    int wait_time = 0;
    for (const int& time : times) {
        wait_time += time;
        sum += wait_time;
    }

    cout << sum;

    return 0;
}