#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int dist[101][101];
vector<int> list[101];
vector<pair<pair<int, int>, int>> city;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dist, 1, sizeof(dist)); // 엄청 큰 수...!
}

void input() {
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        list[a].push_back(b); // 양 방향 그래프
        list[b].push_back(a);
        dist[a][b] = 1; // a와 b의 거리는 1
        dist[b][a] = 1;
    }
}

void dfs(int start,int depth,int ch[]) {
    if (depth == 2) {           
        int temp = 0;
        for (int j = 1; j <= N; j++) {
            if (j == ch[0] || j == ch[1]) {
                continue;
            }
            temp += min(dist[ch[0]][j], dist[ch[1]][j])*2;
        }
        
        city.push_back({{ch[0], ch[1]}, temp});   
    } else {
        for (int i = start; i < N; i++) {
            ch[depth] = i+1;
            dfs(i+1, depth+1, ch);
        }
    }
}

void makeDist(){
    // 플로이드-와샬
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // i -> j ? i -> k - > j
            }
        }
    }
}

void solve() {
    makeDist();
    
    int ch[2];
    dfs(0, 0, ch);
    sort(city.begin(), city.end());

    cout << city[0].first.first << " " << city[0].first.second << " " << city[0].second;
}

int main() {
    init();
    input();
    solve();
}