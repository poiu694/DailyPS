#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int>> piii;

const int MAX = 987654321;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<pair<int, int>> bfs(vector<piii> *graph, int N, int T, int M)
{
    queue<pair<int, pair<int, int>>> q; // next - time / cost
    vector<pair<int, int>> cost;

    for (int i = 0; i <= N; i++)
    {
        cost.push_back({MAX, MAX});
    }

    q.push({1, {0, 0}});

    while (!q.empty())
    {
        int nowCity = q.front().first;
        int nowTime = q.front().second.first;
        int nowCost = q.front().second.second;
        q.pop();

        for (int i = 0; i < graph[nowCity].size(); i++)
        {
            int nextCity = graph[nowCity][i].first;
            int nextTime = graph[nowCity][i].second.first;
            int nextCost = graph[nowCity][i].second.second;

            int sumTime = nowTime + nextTime;
            int sumCost = nowCost + nextCost;
            if (sumTime > cost[nextCity].first && sumCost > cost[nextCity].second)
            {
                continue;
            }
            if (sumTime > T || sumCost > M)
            {
                continue;
            }
            cost[nextCity].first = cost[nextCity].first > sumTime ? sumTime : cost[nextCity].first;
            cost[nextCity].second = cost[nextCity].second > sumCost ? sumCost : cost[nextCity].second;
            q.push({nextCity, {sumTime, sumCost}});
        }
    }

    return cost;
}

void solve()
{
    int N, T, M, L;
    cin >> N >> T >> M >> L;

    vector<piii> graph[101];
    int now, next, minute, cost;
    while (L--)
    {
        cin >> now >> next >> minute >> cost;
        graph[now].push_back({next, {minute, cost}});
        graph[next].push_back({now, {minute, cost}});
    }

    vector<pair<int, int>> result = bfs(graph, N, T, M);
    if (result[N].second >= MAX)
    {
        cout << "-1";
    }
    else
    {
        cout << result[N].second;
    }
}

int main()
{
    fastIO();
    solve();
}