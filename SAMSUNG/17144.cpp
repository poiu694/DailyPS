#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int R, C, T;
int map[51][51]; int copy_map[51][51];
int moveX[4] = { 1,-1,0, 0 }; int moveY[4] = { 0,0,-1,1 };
vector<pair<int, int>> cleaner;
queue<pair<int, int>> q;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> R >> C >> T;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];

            if (map[i][j] == -1) {
                cleaner.push_back({ i, j });
            }
        }
    }
}

void swap(int *a, int *b) {
    int *temp = a;
    a = b;
    b = temp;
}

void expand() {
    // 미세먼지를 q에 삽입
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] >= 5) {
                q.push({ i,j });
            }
        }
    }

    memcpy(copy_map, map, sizeof(map));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int dust = map[x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + moveX[i];
            int ny = y + moveY[i];

            if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
                if (map[nx][ny] != -1) {
                    copy_map[x][y] = copy_map[x][y] - dust / 5;
                    copy_map[nx][ny] = copy_map[nx][ny] + dust / 5;
                }
            }
        }
    }

    memcpy(map, copy_map, sizeof(copy_map));
}

void clean() {
    int topX = cleaner[0].first; int topY = cleaner[0].second;
    int botX = cleaner[1].first; int botY = cleaner[1].second;

    // top부분은 시계방향으로 한 칸씩 이동.
    map[topX - 1][topY] = 0;
    for(int i = topX-2; i >= 0; i--) {
        map[i + 1][0] = map[i][0];
    }
    for (int i = 1; i < C; i++) {
        map[0][i - 1] = map[0][i];
    }
    for (int i = 0; i < topX; i++) {
        map[i][C - 1] = map[i + 1][C - 1];
    }
    for (int i = C - 1; i > 1; i--) {
        map[topX][i] = map[topX][i - 1];
    }
    map[topX][1] = 0;

    // bot부분은 반시계방향으로 한 칸씩 이동
    map[botX + 1][botY] = 0;
    for (int i = botX + 2; i < R; i++) {
        map[i - 1][0] = map[i][0];
    }
    for (int i = 1; i < C; i++) {
        map[R-1][i - 1] = map[R-1][i];
    }
    for (int i = R - 2; i >= botX; i--) {
        map[i + 1][C - 1] = map[i][C - 1];
    }
    for (int i = C - 1; i > 1; i--) {
        map[botX][i] = map[botX][i - 1];
    }
    map[botX][1] = 0;
}

int calculate() {
    int sum = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] > 0) {
                sum += map[i][j];
            }
        }
    }

    return sum;
}

void solve() {
    for (int i = 0; i < T; i++) {
        expand();
        clean();
    }

    cout << calculate();
}

int main() {
    init();
    input();
    solve();
}