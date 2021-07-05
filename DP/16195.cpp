#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 9;

int dp[1001][1001];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int findCase(int n, int m)
{
    if (dp[n][m] != -1)
        return dp[n][m];
    if (m == 1)
        return (n <= 3);
    dp[n][m] = n <= 3;

    for (int i = 1; i <= 3; i++)
    {
        if (n > i)
            dp[n][m] += findCase(n - i, m - 1);
        dp[n][m] %= MOD;
    }

    return dp[n][m];
}

void solve()
{
    int T;
    cin >> T;

    memset(dp, -1, sizeof(dp));

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        cout << findCase(N, M) << '\n';
    }
}

int main()
{
    fastIO();
    solve();
}
