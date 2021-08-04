#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

bool visited[100001];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int bfs(int N, int T, int G)
{
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;

    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cnt > T)
            return -1;

        if (now == G)
            return cnt;

        int next1 = now + 1;
        if (next1 > 99999)
            continue;
        if (!visited[next1])
        {
            q.push({next1, cnt + 1});
            visited[next1] = true;
        }

        int next2 = now * 2;
        if (next2 > 99999)
            continue;
        string digit = to_string(next2);
        next2 = next2 - pow(10, digit.length() - 1);
        if (next2 < 0)
            continue;
        if (!visited[next2])
        {
            q.push({next2, cnt + 1});
            visited[next2] = true;
        }
    }

    return -1;
}

void solve()
{
    int N, T, G;
    cin >> N >> T >> G;

    int ans = bfs(N, T, G);
    if (ans == -1)
        cout << "ANG";
    else
        cout << ans;
}

int main()
{
    fastIO();
    solve();
}
