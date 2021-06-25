#include <iostream>

using namespace std;

int N, L;
int MOD = 1000000007;
int dp[2001][2001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> L;
}

long long dfs(int len, int pastNum) {
    if (dp[pastNum][len] != 0) {
        return dp[pastNum][len];
    }

    if (len == L) {
        return 1;
    }

    long long cnt = 0;
    for (int i = pastNum; i <= N; i+=pastNum) {
        cnt += dfs(len + 1, i);
    }

    dp[pastNum][len] = cnt % MOD;
    return dp[pastNum][len];
}

int main() {
    init();
    input();
    cout << dfs(0, 1);
}