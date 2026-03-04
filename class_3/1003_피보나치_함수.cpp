
#include <bits/stdc++.h>
using namespace std;

// n       0   1   2   3   4
// 0개수    1   0   1   1   2
// 1개수    0   1   1   2   3

typedef pair<int, int> pii;

pii operator+(const pii& a, const pii& b) { return {a.first + b.first, a.second + b.second}; }

// Dynamic Programming = Tabulation
int main_1() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        vector<pii> table(n + 1);
        table[0] = {1, 0};
        table[1] = {0, 1};

        for (int j = 2; j <= n; j++) {
            table[j] = table[j - 2] + table[j - 1];
        }

        cout << table[n].first << ' ' << table[n].second << '\n';
    }

    return 0;
}

pii get_0_and_1_nums(const int& n, vector<pii>& table) {
    if (n == 0) {
        return {1, 0};
    } else if (n == 1) {
        return {0, 1};
    } else if (!(table[n] == pii(-1, -1))) {
        return table[n];
    } else {
        return table[n] = get_0_and_1_nums(n - 2, table) + get_0_and_1_nums(n - 1, table);
    }
}

// Dynamic Programming = Memoization
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        vector<pii> table(n + 1, {-1, -1});
        table[0] = {1, 0};
        table[1] = {0, 1};

        pii result = get_0_and_1_nums(n, table);

        cout << result.first << ' ' << result.second << '\n';
    }

    return 0;
}