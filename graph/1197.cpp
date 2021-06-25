#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 2147483647;
int V, E; 
vector<pair<int, int>> graph[10001]; // node - child&value
priority_queue<pair<int, int>, vector<int, int> less<int>> pq; // node & value


void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> V >> E;

    int node, child, value;
    for(int i=0; i<E; i++){
        cin >> node >> child >> value;

        // 양방향
        graph[node].push_back({child, value}); // node -> value
        graph[child].push_back({node, value}); // child -> node
    }
}

vector<int> dijkstra(int node){
    vector<int> dist(V+1, MAX);
    dist[node] = 0;
    pq.push({node, 0});

    while(!pq.empty()){
        int nowNode = pq.front().first;
        int nowDist = pq.front().second;

        if(nowDist > dist[node]){
            continue;
        }

        for(int i=0; i<graph[nowNode].size(); i++){
            int nextNode = graph[nowNode][i].first;
            int nextDist = graph[nowNode][i].second;

            if(nowDist + nextDist < dist[nextNode]){
                dist[nextNode] = nowDist + nextDist;
                pq.push({nextNode, dist[nextNode]});
            }
        }
    }

    return dist;
}

void solve(){
    vector<int> result = dijkstra(0);

    int sum = 0;
    for(int i=0; i<result.size(); i++){
        sum += result[i];
    }

    cout << sum;
}

int main(){
    init();
    input();
}