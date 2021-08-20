#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 987654321;

vector<int> dijkstra(int N, vector<vector<pair<int, int>>> graph)
{
    priority_queue<pair<int, int>> pq; // dist, node;
    vector<int> dist(N + 1, MAX);

    dist[1] = 0; // 1 to 1 : dist 0
    pq.push({0, 1});

    while (!pq.empty())
    {
        int nowDist = -pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();

        for (auto next : graph[nowNode])
        {
            int nextNode = next.first;
            int nextDist = next.second;

            if (nowDist + nextDist < dist[nextNode])
            {
                dist[nextNode] = nowDist + nextDist;
                pq.push({-dist[nextNode], nextNode});
            }
        }
    }

    return dist;
}

vector<vector<pair<int, int>>> makeGraphFromRoad(int N, vector<vector<int>> road)
{
    vector<vector<pair<int, int>>> ret(N + 1);
    for (auto a : road)
    {
        int now = a[0];
        int next = a[1];
        int dist = a[2];

        ret[now].push_back({next, dist});
        ret[next].push_back({now, dist});
    }
    return ret;
}

int solution(int N, vector<vector<int>> road, int K)
{
    vector<vector<pair<int, int>>> graph = makeGraphFromRoad(N, road);
    vector<int> dists = dijkstra(N, graph);

    int answer = 0;
    for (int dist : dists)
    {
        if (dist <= K)
            answer++;
    }
    return answer;
}