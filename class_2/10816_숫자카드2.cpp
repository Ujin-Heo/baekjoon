#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, int> cards;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cards[x] += 1;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << cards[x] << ' ';
    }

    return 0;
}