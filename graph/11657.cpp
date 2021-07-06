#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

const int INF = 987654321;

vector<pair<int, int>> cities[501];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<long long> getDist(int N)
{
    vector<long long> dist(N + 1);
    for (int i = 1; i <= N; i++)
        dist[i] = INF;

    dist[1] = 0;
    bool cycle = false;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (auto city : cities[j])
            {
                int next = city.first;
                int nextValue = city.second;

                if (dist[j] != INF && dist[next] > nextValue + dist[j])
                {
                    dist[next] = nextValue + dist[j];

                    if (i == N)
                    {
                        cycle = true;
                    }
                }
            }
        }
    }

    if (cycle)
        return {};
    else
    {
        for (int i = 0; i < dist.size(); i++)
        {
            if (dist[i] == INF)
                dist[i] = -1;
        }
        return dist;
    }
}

void solve()
{
    int N, M;
    cin >> N >> M;

    int now, next, value;
    for (int i = 0; i < M; i++)
    {
        cin >> now >> next >> value;
        cities[now].push_back({next, value});
    }

    vector<long long> dist = getDist(N);
    if (dist.size() == 0)
        cout << "-1";
    else
    {
        for (int i = 2; i <= N; i++)
        {
            cout << dist[i] << '\n';
        }
    }
}

int main()
{
    fastIO();
    solve();
}
