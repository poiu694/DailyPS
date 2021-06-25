#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int dist[101][101];
vector<pair<int, int>> graph[101];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N >> M;

    int p, c, v;
    for(int i=0; i<M; i++){
        cin >> p >> c >> v;
        
        graph[p].push_back({c, v});
    }
}

void makeGraph(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void init(){
    memset(dist, 1, sizeof(dist));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j){
                dist[i][j] = 0;
            }
        }
    }
}

void printGraph(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}

void solve(){
    init();
    makeGraph();
    printGraph();
}

int main(){
    fastIO();
    input();
    solve();
}