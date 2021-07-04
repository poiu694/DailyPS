#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void init()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int S;
int minCnt;
queue<pair<pair<int, int>, int>> q;
int dp[2050][2000]; // dp[display][clip] = min
int result = 999999999;

void bfs()
{
    q.push({{1, 0}, 0});
    memset(dp, -1, sizeof(dp));
    while (!q.empty())
    {
        int display = q.front().first.first;
        int clip = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (display == S)
        {
            result = result > cnt ? cnt : result;
            continue;
        }
        else if (display >= S + 1)
        {
            continue;
        }
        if (dp[display][display] == -1)
        {
            dp[display][display] = cnt + 1;
            q.push({{display, display}, cnt + 1});
        }
        if (dp[display + clip][clip] == -1)
        {
            dp[display + clip][clip] = cnt + 1;
            q.push({{display + clip, clip}, cnt + 1});
        }
        if (dp[display - 1][clip] == -1)
        {
            dp[display - 1][clip] = cnt + 1;
            q.push({{display - 1, clip}, cnt + 1});
        }
    }
}

int main()
{
    init();
    cin >> S;
    bfs();
    cout << result;

    return 0;
}