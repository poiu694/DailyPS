#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int map[501][501];
int dp[501][501];
int moveX[4] = { 1, -1, 0, 0 };
int moveY[4] = { 0, 0, 1, -1 };


void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

int dfs(int nx, int ny) {
    if (nx == N - 1 && ny == M - 1) {
        return 1;
    }

    if (dp[nx][ny] != -1) {
        return dp[nx][ny];
    }

    dp[nx][ny] = 0;
    for (int i = 0; i < 4; i++) {
        int dx = nx + moveX[i];
        int dy = ny + moveY[i];

        if (dx >= 0 && dy >= 0 && dx < N && dy < M) {
            if (map[dx][dy] < map[nx][ny]) {
                dp[nx][ny] = dp[nx][ny] + dfs(dx, dy);
            }
        }
    }

    return dp[nx][ny];
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int cnt = dfs(0, 0);
    cout << cnt;
}

int main() {
    init();
    input();
    solve();
}