#include <iostream>

using namespace std;

long long N;
int dp[1500001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;
}

void solve() {
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= 1500000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
    }
    cout << dp[N%1500000];
}

int main() {
    init();
    input();
    solve();
}