#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
    int ND;
    int HP;
    int FG; // Feel Good ~
}hiking;

int N, edge, D, E;
bool visited[100001];
vector<int> height;
vector<pair<int, int>> graph[100001];
queue<hiking> q;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N >> edge >> D >> E;
    
    int a, b, c;
    for(int i=0; i<N; i++){
        cin >> a;
        height[i] = a;
    }

    for(int i=0; i<edge; i++){
        cin >> a >> b >> c;
        
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}

void bfs(){
    q.push({1, 0, 0});

    while(!q.empty()){
        int node = q.front().ND;
        int nowHP = q.front().HP;
        int nowFG = q.front().FG;
        q.pop();

        visited[node] = true;
        for(int i=0; i<N; i++){
            int nextNode = 
            if(!visited[i] && height[node] >)
        }
    }
}

void solve(){
}

int main(){
    init();
    input();
    solve();
}