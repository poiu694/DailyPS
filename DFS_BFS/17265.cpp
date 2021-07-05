#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

char map[6][6];
int mx = -987654321;
int mn = 987654321;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int calculator(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '*')
        return a * b;
    if (op == '-')
        return a - b;
    return b;
}

void dfs(int x, int y, int now, char op, int N)
{
    if (x == N - 1 && y == N - 1)
    {
        int num = map[x][y] - '0';
        now = calculator(now, num, op);
        if (mx < now)
            mx = now;
        if (mn > now)
            mn = now;
        return;
    }

    if (x >= N || y >= N)
        return;

    // op
    if ((x + y) % 2 == 1)
    {
        dfs(x + 1, y, now, map[x][y], N);
        dfs(x, y + 1, now, map[x][y], N);
    }
    else
    {
        // number
        int num = map[x][y] - '0';
        int next = calculator(now, num, op);

        dfs(x + 1, y, next, '^', N);
        dfs(x, y + 1, next, '^', N);
    }
}

void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    dfs(0, 0, 0, '^', N);
    cout << mx << " " << mn;
}

int main()
{
    fastIO();
    solve();
}
