#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 987654321;
int V, E, K;
priority_queue<pair<int, int>> pq; // cost&node
vector<pair<int, int>> tree[20001]; // node - child&value

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> V >> E >> K;

    for (int i = 0; i < E; i++) {
        int node, child, value;

        cin >> node >> child >> value;
        tree[node].push_back({ child, value });
    }
}

vector<int> dijkstra(int node) {
    vector<int> dist(V+1, MAX);
    pq.push({ 0, node });
    dist[node] = 0;

    while (!pq.empty()) {
        int nowDist = -pq.top().first; // pq는 기본 내림차순 정렬이므로 부호를 반대로 넣고, 반대로해서 빼면 오름차순 정렬을 할 수 있다. 
        int nowNode = pq.top().second;
        pq.pop();

        // 이어진 값보다 기존값을 쓰는게 빠르므로 넘긴다.
        if (nowDist > dist[nowNode]) {
            continue;
        }

        //현재 node와 연결되있는 점을 모두 탐방한다
        for (int i = 0; i < tree[nowNode].size(); i++) {
            int nextNode = tree[nowNode][i].first; // child
            int nextDist = tree[nowNode][i].second; // value

            // dist를 갱신할 수 있으면 갱신하고 push한다. 그 노드에서 다시 처음부터 거리를 확인을 하면 dist가 더 갱신될 수 있다.
            if (nextDist + nowDist < dist[nextNode]) {
                dist[nextNode] = nextDist + nowDist;

                pq.push({ -dist[nextNode], nextNode });
            }
        }
    }

    return dist;
}

void solve() {
    vector<int> result = dijkstra(K);

    for (int i = 1; i <= V; i++) {
        if (result[i] == MAX) {
            cout << "INF" << "\n";
        }
        else {
            cout << result[i] << "\n";
        }
    }
}

int main() {
    init();
    input();
    solve();
}