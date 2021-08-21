#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Force
{
    int x;
    int y;
    int time;
    bool haveSword;
};

int map[101][101];
bool visited[101][101][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int bfs(int N, int M, int T)
{
    memset(visited, false, sizeof(visited));
    queue<Force> q;

    q.push({0, 0, 0, false});
    visited[0][0][0] = true;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int time = q.front().time;
        bool haveSword = q.front().haveSword;
        q.pop();

        if (x == N - 1 and y == M - 1)
        {
            return time;
        }

        if (time > T)
            return -1;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 or ny < 0 or nx >= N or ny >= M)
                continue;
            if (map[nx][ny] == 1 && !haveSword)
                continue;
            if (visited[nx][ny][haveSword])
                continue;

            if (map[nx][ny] == 2)
                haveSword = true;
            visited[nx][ny][haveSword] = true;
            q.push({nx, ny, time + 1, haveSword});
        }
    }

    return -1;
}

void solve()
{
    int N, M, T;
    cin >> N >> M >> T;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    int minTime = bfs(N, M, T);
    if (minTime == -1)
        cout << "Fail";
    else
        cout << minTime;
}

int main()
{
    fastIO();
    solve();
}
