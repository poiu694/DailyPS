#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool visited[1001];
vector<int> graph[1001];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int node, int depth, int N){
    if(depth == N){
        return;
    }

    cout << node << " ";
    visited[node] = true;
    for(int i=0; i<graph[node].size(); i++){
        int nextNode = graph[node][i];

        if(!visited[nextNode]){
            dfs(nextNode, depth +1, N);
        }
    }
}

void bfs(int node, int N){
    queue<int> q;
    q.push(node);

    int depth = 0;
    while(!q.empty()){
        int nowNode = q.front();
        q.pop();

        cout << nowNode << " ";
        if(depth == N){
            return;
        }

        visited[nowNode] = true;
        depth++;
        for(int i=0; i<graph[node].size(); i++){
            int nextNode = graph[node][i];

            if(!visited[nextNode]){
                q.push(nextNode);
            }
        }
    }
}

void solve(){
    int N, M, startNode;
    cin >> N >> M >> startNode;

    for(int i=0; i<M; i++){
        int parent, child;
        cin >> parent >> child;
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }

    dfs(startNode, 1, N);
    cout << endl;
    memset(vistied, false, sizeof(visited));
    bfs(startNode, N);
}

int main(){
    fastIO();
    solve();
}
