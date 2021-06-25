#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int dist[201][201];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void makeDist(){
    memset(dist, 1, sizeof(dist));

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void solve(){
    makeDist();
    cin >> N >> M;

    int node, child, value;
    for(int i=0; i<M; i++){
        cin >> node >> child >> value;
        dist[node][child] = value;
        dist[child][node] = value;
    }

    int min = 987654321;

    for(int i=1; i<=N; i++){
        int sum = 0;
        for(int j=1; j<=N; j++){
            sum += dist[i][j];
        }

        min = sum < min ? sum : min;
    }

    cout << min;
}

int main(){
    fastIO();
    solve();
}