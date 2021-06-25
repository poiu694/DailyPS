#include <iostream>
#include <algorithm>
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
    int N;
    cin >> N;
    vector<int> list(N + 1);

    int dp[2001];
    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> list[i];
    }

    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (list[i] < list[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        if (max < dp[i])
            max = dp[i];
    }

    cout << N - max;
}

int main()
{
    fastIO();
    solve();
}