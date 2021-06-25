#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 987654321;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // Direction (N-E-S-W)
int W, H;
int minTime = MAX;
char map[501][501];
priority_queue<pair<int, pair<int, int>>> pq; // (x&y)&cost
bool visited[501][501];

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

pair<int, pair<int,int>> moveTerra(int x, int y, int dir)
{
    int move = 0;
    while (true)
    {
        x = x + dx[dir];
        y = y + dy[dir];
        move++;
        if (x < 0 || y < 0 || x >= W || y >= H || 
                map[x][y] == 'H' || map[x][y] == 'R')
        {
            return {-1,{-1,-1}};
        }

        if(map[x][y] == 'E'){
            return {move, {x,y}};
        }
    }

    return {move, {x,y}};
}

void bfs() {
    memset(visited, false, sizeof(visited));

    while (!pq.empty()) {
        int nowX = pq.top().second.first;
        int nowY = pq.top().second.second;
        int nowCost = -pq.top().first;
        pq.pop();

        visited[nowX][nowY] = true;
        for(int i=0; i<4; i++){
            auto next = moveTerra(nowX, nowY, i);

            if(next.first == -1){
                continue;
            }
            if(map[next.second.first][next.second.second] == 'E'){
                minTime = nowCost + next.first;
            }
            pq.push({nowCost + next.first, {next.second.first, next.second.second}});
        }
    }
}

void solve() {
    cin >> H >> W;

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'T') {
                pq.push({ 0, { i, j } });
            }
        }
    }
    bfs();

    if (minTime == MAX) {
        minTime = -1;
    }
    cout << minTime;
}

int main() {
    fastIO();
    solve();
}