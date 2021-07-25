#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <limits.h>

using namespace std;

const int MOD = 1e9 + 7;

vector<int> graph[200005];
int dist[200005];
int dp[200005];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(5);
    cout << fixed;
}

void solve()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int now, next;
        cin >> now >> next;

        graph[now].push_back(next);
        graph[next].push_back(now);
    }
    memset(dist, 1, sizeof(dist));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    dp[1] = 1;

    long long ans = 0;
    int shortPath = -1;
    while (!pq.empty())
    {
        int nowDist = pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();

        if (dist[nowNode] < nowDist)
            continue;

        for (auto next : graph[nowNode])
        {
            int nextDist = nowDist + 1;
            if (dist[next] > nextDist)
            {
                dp[next] = dp[nowNode] % MOD;
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
            else if (dist[next] == nextDist)
            {
                dp[next] += dp[nowNode];
                dp[next] %= MOD;
            }
        }
    }

    cout << dp[N];
}

int main()
{
    fastIO();
    solve();
}
