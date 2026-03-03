#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    int remain = n;
    int x;
    while (remain >= 2) {
        dq.pop_front();

        x = dq.front();
        dq.pop_front();
        dq.push_back(x);

        remain -= 1;
    }

    cout << dq.front();

    return 0;
}