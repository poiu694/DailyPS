#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int dp[100001];
    int N, K;
    cin >> N >> K;

    memset(dp, 1, sizeof(dp)); // dp에 큰 숫자들 저장

    vector<int> list(N);
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
        dp[list[i]] = 1;
    }

    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j < list.size(); j++)
        {
            if (i - list[j] < 0)
                continue;
            dp[i] = min(dp[i], dp[i - list[j]] + 1);
        }
    }

    if (dp[K] == 16843009)
        dp[K] = -1;
    cout << dp[K];
}

int main()
{
    fastIO();
    solve();
}
