#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 세로 가로
    int n, m;
    cin >> n >> m;
    cin.ignore();

    // vector<vector<int>> v(n, vector<int>(m, 0));
    vvi v(n, vi(m, 0));

    // 왼쪽 위가 흰색일 때, 바꿔야 될 칸을 1로 표시하기
    string str;
    bool shouldBeWhite = true;
    for (int row = 0; row < n; row++) {
        getline(cin, str);
        for (int col = 0; col < m; col++) {
            if (shouldBeWhite) {
                v[row][col] = (str[col] == 'W') ? 0 : 1;
            } else {
                v[row][col] = (str[col] == 'B') ? 0 : 1;
            }
            shouldBeWhite = !shouldBeWhite;
        }
        if (m % 2 == 0) shouldBeWhite = !shouldBeWhite;
    }

    // 가능한 8*8 영역 합 모두 구하기
    vector<int> counts;
    for (int row = 0; row < n - 7; row++) {
        for (int col = 0; col < m - 7; col++) {
            int sum = 0;
            for (int i = row; i < row + 8; i++) {
                for (int j = col; j < col + 8; j++) {
                    sum += v[i][j];
                }
            }
            counts.push_back(sum);
        }
    }

    // 최솟값 구하기
    sort(counts.begin(), counts.end());  // 오름차순
    int min_val = min(counts.front(), 64 - counts.back());
    cout << min_val;

    return 0;
}