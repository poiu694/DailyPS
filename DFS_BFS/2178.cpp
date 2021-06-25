#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[101][101] = {0};
bool check[101][101] = { false };
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
queue<pair<pair<int, int>, int>> q;

int bfs(){
    q.push({{1,1}, 1});
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        // 종료 조건
        if(x == N && y == M){
            return cnt;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 1 && nx <= N && ny >= 1 && ny <=M){
                if(map[nx][ny] && !check[nx][ny]){
                    check[nx][ny] = true;
                    q.push({{nx,ny}, cnt+1});
                }
            }
        }
    }
    
}

void input(){
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d", &map[i][j]);
        }
    }
}

int main(){
    input();
    cout << bfs();
}