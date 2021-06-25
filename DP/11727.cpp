#include <iostream>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int N;
    int dp[1001];
    cin >> N;

    // 1 3 5 10
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= N; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }

    cout << dp[N];
}

int main()
{
    fastIO();
    solve();
}
