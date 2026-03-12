#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_multimap<int, int> network;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        network.insert({a, b});
        network.insert({b, a});
    }

    unordered_set<int> visited;
    queue<int> to_lookup;
    to_lookup.push(1);
    visited.insert(1);

    int pos;
    while (to_lookup.size()) {
        pos = to_lookup.front();
        to_lookup.pop();

        auto range = network.equal_range(pos);
        for (auto it = range.first; it != range.second; ++it) {
            if (!visited.count(it->second)) {
                to_lookup.push(it->second);
                visited.insert(it->second);
            }
        }
    }

    cout << (int)visited.size() - 1;

    return 0;
}