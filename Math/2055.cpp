#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1001][4];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int nCk(int N, int K)
{
    if (N == K || K == 0)
    {
        return 1;
    }
    if (dp[N][K] != 0)
    {
        return dp[N][K];
    }

    return dp[N][K] = nCk(N - 1, K - 1) + nCk(N - 1, K);
}

int getTrace(int big, int small)
{
    int cnt = 0;

    if (big == small)
    {
        cnt += nCk(big, 3);
        big--;

        while (big != 2)
        {
            cnt += nCk(big, 3) * 2;
            big--;
        }
    }
    else
    {
        cnt += nCk(big, 3) * (big - small + 1);
        big--;

        while (big != 2)
        {
            cnt += nCk(big, 3) * 2;
            big--;
        }
    }

    return cnt * 2;
}

void find_tri(int a, int b)
{
    a++;
    b++;

    if (a < 3 && b < 3)
    {
        cout << nCk(a * b, 3);
        return;
    }
    else if (a < 3 || b < 3)
    {
        int cnt = 0;

        int l = max(a, b);
        int s = min(a, b);

        cnt += nCk(l, 2) * l * (s - 1) * s;
        cout << cnt;
    }
    else
    {
        int cnt = 0;

        int l = max(a, b);
        int s = min(a, b);

        cnt += nCk(l, 2) * l * (s - 1) * s; // Select 2point - 1point
        // Select 1point - 1point - 1point
        cnt += l * l * l * nCk(l, 3) - nCk(s, 3) * l - nCk(l, 3) * s; // horizon
        cnt -= getTrace(l, s);                                        // trace

        cout << cnt;
    }
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    int a, b;
    cin >> a >> b;

    find_tri(a, b);
}

int main()
{
    fastIO();
    solve();
}