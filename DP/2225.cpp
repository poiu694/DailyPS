#include <iostream>

using namespace std;

const int MOD = 1000000000;
int N, K;
long long dp[201][201];


void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> K;
}


// n+k-1 C k-1
void solve() {
    // dp[a][b] = c -> a개 더해서 b가 나오는 경우의 수는 1
    for (int i = 0; i <= N; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
            }
            dp[i][j] %= MOD;
        }
    }

    cout << dp[K][N];
}

int main() {
    init();
    input();
    solve();
}