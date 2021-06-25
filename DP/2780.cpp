#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1234567;
int dp[1001][11]; // adj matrix

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long findPW(int num, int depth, int len)
{
    if (len == depth)
    {
        return 1;
    }

    if (dp[depth][num] != -1)
    {
        return dp[depth][num];
    }

    long long sum = 0;
    switch (num)
    {
    case 0:
        sum += findPW(7, depth + 1, len) % MOD;
        break;
    case 1:
        sum += (findPW(2, depth + 1, len) + findPW(4, depth + 1, len)) % MOD;
        break;
    case 2:
        sum += (findPW(1, depth + 1, len) + findPW(3, depth + 1, len) + findPW(5, depth + 1, len)) % MOD;
        break;
    case 3:
        sum += (findPW(2, depth + 1, len) + findPW(6, depth + 1, len)) % MOD;
        break;
    case 4:
        sum += (findPW(1, depth + 1, len) + findPW(5, depth + 1, len) + findPW(7, depth + 1, len)) % MOD;
        break;
    case 5:
        sum += (findPW(2, depth + 1, len) + findPW(4, depth + 1, len) + findPW(6, depth + 1, len) + findPW(8, depth + 1, len)) % MOD;
        break;
    case 6:
        sum += (findPW(3, depth + 1, len) + findPW(5, depth + 1, len) + findPW(9, depth + 1, len)) % MOD;
        break;
    case 7:
        sum += (findPW(4, depth + 1, len) + findPW(8, depth + 1, len) + findPW(0, depth + 1, len)) % MOD;
        break;
    case 8:
        sum += (findPW(5, depth + 1, len) + findPW(7, depth + 1, len) + findPW(9, depth + 1, len)) % MOD;
        break;
    case 9:
        sum += (findPW(6, depth + 1, len) + findPW(8, depth + 1, len)) % MOD;
        break;
    }

    return dp[depth][num] = sum % MOD;
}

void solve()
{
    int T;
    cin >> T;

    while (T--)
    {
        memset(dp, -1, sizeof(dp));

        int pwLen;
        cin >> pwLen;

        long long sum = 0;
        for (int i = 0; i < 10; i++)
        {
            sum += findPW(i, 1, pwLen) % MOD;
        }

        cout << sum % MOD << '\n';
    }
}

int main()
{
    fastIO();
    solve();
}