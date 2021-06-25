#include <iostream>
#include <vector>

using namespace std;

const int MAX = 987654321;
int N;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    cin >> N;

    vector<int> dp(N + 1, MAX);
    dp[3] = 1; dp[5] = 1;

    for (int i = 6; i <= N; i++) {
        dp[i] = min(dp[i - 5] + 1, dp[i - 3] + 1);
    }

    if (dp[N] >= MAX) {
        cout << "-1";
    }
    else {
        cout << dp[N];
    }
}

int main() {
    init();
    solve();
}