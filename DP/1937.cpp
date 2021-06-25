#include <iostream>
#include <cstring>

using namespace std;

int N;
int map[501][501]; int dp[501][501];
int moveX[4] = { 1, -1, 0, 0 }; int moveY[4] = { 0, 0, 1, -1 };
bool visited[501][501];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = 1;
        }
    }
}

int dfs(int x, int y) {
    if (visited[x][y]) {
        return dp[x][y];
    }

    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + moveX[i];
        int ny = y + moveY[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
            if (map[nx][ny] > map[x][y]) {
                dp[x][y] = (dp[x][y] > dfs(nx, ny) + 1) ? dp[x][y] : dfs(nx, ny) + 1;
            }
        }
    }
    return dp[x][y];
}

void solve() {
    int max = -987654321;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dfs(i, j);

            if (max < dp[i][j]) {
                max = dp[i][j];
            }
        }
    }

    cout << max;
}

int main() {
    init();
    input();
    solve();
}