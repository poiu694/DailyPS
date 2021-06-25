#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int dp[1001][1001];
int map[1001][1001];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    int N, M;
    cin >> N >> M;

    string target;
    for (int i = 0; i < N; i++)
    {
        cin >> target;
        for (int j = 0; j < target.length(); j++)
        {
            map[i][j] = target[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = map[i][j];
                continue;
            }
            if (i == 0)
            {
                dp[i][j] = max(map[i][j - 1], map[i][j]);
                continue;
            }

            if (j == 0)
            {
                dp[i][j] = max(map[i - 1][j], map[i][j]);
                continue;
            }

            int maxTemp = dp[i - 1][j - 1];
            int midTemp = dp[i - 1][j];
            int minTemp = dp[i][j - 1];

            if (maxTemp < midTemp)
            {
                int temp = maxTemp;
                maxTemp = midTemp;
                midTemp = temp;
            }
            if (midTemp < minTemp)
            {
                int temp = midTemp;
                midTemp = minTemp;
                minTemp = temp;
            }
            if (maxTemp < midTemp)
            {
                int temp = maxTemp;
                maxTemp = midTemp;
                midTemp = temp;
            }

            if (map[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            if (map[i - 1][j] == 0 || map[i - 1][j - 1] == 0 || map[i][j - 1] == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = minTemp + 1;
        }
    }

    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ans = ans < dp[i][j] ? dp[i][j] : ans;
        }
    }

    cout << ans * ans;
}

int main()
{
    fastIO();
    solve();
}
