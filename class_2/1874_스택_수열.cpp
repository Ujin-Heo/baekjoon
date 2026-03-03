#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> stk;

    // 출력할 수열을 입력받음(목표)
    vector<int> nums;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    bool NO = false;
    vector<string> strs;
    vector<int>::iterator next = nums.begin();
    int to_push = 1;
    while (true) {
        if (stk.empty()) {
            // 스택이 비었을 때:
            // 아직 들어올 수가 남았으면 스택에 넣고 아니면 끝냄.
            if (to_push <= n) {
                strs.push_back("+");
                stk.push(to_push);
                to_push += 1;
            } else {
                break;
            }
        }
        // 다음으로 출력할 수(*next)보다 작은 수들은 바로 스택에 push함
        // 다음으로 출력할 수(*next)보다 더 큰 수가 들어오면 -> 영원히 pop 불가!!
        else if (*next == stk.top()) {
            strs.push_back("-");
            stk.pop();
            next += 1;
        } else if (*next >= to_push) {
            strs.push_back("+");
            stk.push(to_push);
            to_push += 1;
        } else if (*next < to_push) {
            NO = true;
            cout << "NO";
            break;
        }
    }

    if (!NO) {
        for (const auto& str : strs) {
            cout << str << '\n';
        }
    }

    return 0;
}