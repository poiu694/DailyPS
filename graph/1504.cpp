#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int N, E, V1, V2;
vector<pair<int, int>> tree[801]; // node-child&value
priority_queue<pair<int, int>> pq; // node&value 

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N >> E;

    for(int i=0; i<E; i++){
        int node, child, value;

        cin >> node >> child >> value;
        tree[node].push_back({child, value});
    }
    cin >> V1 >> V2;
}

vector<int> dijkstra(int node){
    vector<int> dist(N+1, INT_MAX);
    dist[node] = 0;
    pq.push({node, 0});

    while(!pq.empty()){
        int nowNode = pq.top().first;
        int nowDist = pq.top().second;

        if(nowDist > dist[nowNode]){
            continue;
        }

        for(int i=0; i<tree[nowNode].size(); i++){
            int nextNode = tree[nowNode][i].first;
            int nextDist = tree[nowNode][i].second;

            if(nowDist + nextDist < dist[nextNode]){
                dist[nextNode] = nowDist + nextDist;
                pq.push({nextNode, dist[nextNode]});
            }
        }
    }
    return dist;
}

void solve(){
    vector<int> result = dijkstra(1);

    cout << result[4];
}

int main(){
    init();
    input();
    solve();
}