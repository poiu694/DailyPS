#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int x, y, z;
    int cnt;
} types;

int M, N, H; //가로 세로 높이
int box[101][101][101];
bool visited[101][101][101];
int moveX[6] = { 1, -1, 0, 0, 0, 0 };
int moveY[6] = { 0, 0, 1, -1, 0, 0 };
int moveZ[6] = { 0, 0, 0, 0, 1, -1 };
queue<types> q;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> M >> N >> H;

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    q.push({ i, j, k, 0 });
                    visited[i][j][k] = true;
                }
                else if (box[i][j][k] == -1)
                    visited[i][j][k] = true;
            }
        }
    }
}

int bfs() {
    int cnt = 0;

    while (!q.empty()) {
        auto a = q.front();
        q.pop();
        cnt = cnt > a.cnt ? cnt : a.cnt;

        for (int i = 0; i < 6; i++) {
            int nx = a.x + moveX[i];
            int ny = a.y + moveY[i];
            int nz = a.z + moveZ[i];

            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < N && ny < M && nz < H && !visited[nx][ny][nz]) {
                q.push({ nx, ny, nz, a.cnt + 1 });
                visited[nx][ny][nz] = true;
            }
        }
    }
    
    return cnt;
}

bool is_finish() {
    bool flag = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < H; k++) {
                if (!visited[i][j][k]) {
                    flag = false;
                    return flag;
                }
            }
        }
    }

    return flag;
}

void solve() {
    if (q.empty()) {
        cout << -1;
        return;
    }
    else {
        int result = bfs();
        if (!is_finish()) {
            result = -1;
        }
        cout << result;
    }
}

int main(void) {
    init();
    input();
    solve();
}