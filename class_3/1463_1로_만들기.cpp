#include <bits/stdc++.h>
using namespace std;

// n:        1   2  3   4
// 최소 횟수: 0   1  1

// dynamic programming - memoization
int get_min_operation_num(const int& n, vector<int>& table) {
    if (table[n] > -1) {
        return table[n];
    } else if (n % 3 == 0 && n % 2 == 0) {
        return table[n] = min(get_min_operation_num(n / 3, table),
                              min(get_min_operation_num(n / 2, table),
                                  get_min_operation_num(n - 1, table))) +
                          1;
    } else if (n % 3 == 0) {
        return table[n] =
                   min(get_min_operation_num(n / 3, table), get_min_operation_num(n - 1, table)) +
                   1;
    } else if (n % 2 == 0) {
        return table[n] =
                   min(get_min_operation_num(n / 2, table), get_min_operation_num(n - 1, table)) +
                   1;
    } else {
        return table[n] = get_min_operation_num(n - 1, table) + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> table(n + 1, -1);
    table[1] = 0;
    table[2] = 1;
    table[3] = 1;

    int result = get_min_operation_num(n, table);
    cout << result;

    return 0;
}