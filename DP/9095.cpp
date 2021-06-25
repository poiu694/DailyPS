#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> num;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> T;

    int temp;
    while (T--) {
        cin >> temp;
        num.push_back(temp);
    }
}

void solve() {
    int dp[12] = { 0, };
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    // dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for (int i = 0; i < num.size(); i++) {
        int temp = num[i];

        cout << dp[temp] << '\n';
    }
}

int main() {
    init();
    input();
    solve();
}