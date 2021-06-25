#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, temp;
priority_queue<int, vector<int>, greater<int>> minQ;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    cin >> N;

    while (N--) {
        cin >> temp;

        // 출력
        if (temp == 0) {
            // 비어있다면
            if (minQ.empty()) {
                cout << '0' << '\n';
            }
            // 비어있지 않다면
            else {
                cout << minQ.top() << '\n';
                minQ.pop();
            }
        }
        // 입력
        else {
            minQ.push(temp);
        }
    }
}

int main() {
    init();
    solve();
}