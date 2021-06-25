#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int T, N, M, answer;
bool visited[1001];
vector<int> list[1001];
queue<pair<int, int>> q;


void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N >> M;

        for(int i=0; i<M; i++){
            int a, b;
            cin >> a >> b;

            list[a].push_back(b);
            list[b].push_back(a);
        }
        solve();
    }
}

void bfs(int index){
    q.push({index,0});
    visited[index]= true;

    while(!q.empty()){
        int node = q.front().first;
        int cnt = q.front().second;
        answer = cnt;
        q.pop();

        visited[node] = true;
        for(int i=0; i<list[node].size(); i++){
            int nextNode = list[node][i];
            int nextCnt = cnt + 1;

            if(visited[nextNode]){
                continue;
            }else{
                visited[nextNode] = true;
                q.push({nextNode, nextCnt});
            }
        }
    }
}

void solve(){
    memset(visited, false, sizeof(visited));
    bfs(1);
    cout << answer << "\n";
}

int main(){
    init();
    input();
}