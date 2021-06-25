#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 987654321;
int N, M, startCity, endCity;
int minCost = MAX;
vector<pair<int, int>> city[1001]; // city - neighbor&cost
priority_queue<pair<int, int>> pq; // city&cost

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> N >> M;

    int a, b, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> cost;

        city[a].push_back({b, cost});
    }

    cin >> startCity >> endCity;
}

vector<int> dijkstra(int node)
{
    vector<int> dist(N + 1, MAX);
    pq.push({0, node});
    dist[node] = 0;

    while (!pq.empty())
    {
        int nowDist = -pq.top().first; // pq는 기본 내림차순 정렬이므로 부호를 반대로 넣고, 반대로해서 빼면 오름차순 정렬을 할 수 있다.
        int nowNode = pq.top().second;
        pq.pop();

        // 이어진 값보다 기존값을 쓰는게 빠르므로 넘긴다.
        if (nowDist > dist[nowNode])
        {
            continue;
        }

        //현재 node와 연결되있는 점을 모두 탐방한다
        for (int i = 0; i < tree[nowNode].size(); i++)
        {
            int nextNode = tree[nowNode][i].first;  // child
            int nextDist = tree[nowNode][i].second; // value

            // dist를 갱신할 수 있으면 갱신하고 push한다. 그 노드에서 다시 처음부터 거리를 확인을 하면 dist가 더 갱신될 수 있다.
            if (nextDist + nowDist < dist[nextNode])
            {
                dist[nextNode] = nextDist + nowDist;

                pq.push({-dist[nextNode], nextNode});
            }
        }
    }

    return dist;
}

void solve()
{
    vector<int> result = dijkstra(startCity);
    vector<int> result2 = dijkstra(2);
    // ...
    vector<int> resultN = 
    cout << result[endCity];
}

int main()
{
    init();
    input();
    solve();
}