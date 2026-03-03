// 키워드: unordered_set
// 1. 듣에대해 unordered_set을 만들고, 보의 이름을 하나씩 거기에서 찾는다.
// (순서 상관x, 존재여부 확인 -> unordered_set)
// 2. 듣에 존재하는 이름만 새로운 vector에 저장하고, sort하여 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // n * O(1) = n = 5*10^5
    unordered_set<string> unheard;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        unheard.insert(name);
    }

    // m * O(1) = m = 5*10^5
    vector<string> unheard_unseen;
    for (int i = 0; i < m; i++) {
        cin >> name;
        if (unheard.count(name)) {           // O(1)
            unheard_unseen.push_back(name);  // O(1)
        }
    }

    // 겹치는 최대 수를 n이라 하자
    // O(n log n) = 5*10^5
    sort(unheard_unseen.begin(), unheard_unseen.end());
    cout << (int)unheard_unseen.size() << '\n';
    for (const auto& name : unheard_unseen) {
        cout << name << '\n';
    }

    // 총 시간복잡도: 3*5*10^5 = 1.5*10^6
    // 시간제한: 2초 = 2*10^8

    return 0;
}