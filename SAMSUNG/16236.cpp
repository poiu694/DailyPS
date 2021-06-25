#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 987654321;

int N;
bool visited[21][21];
int map[21][21];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int getDist(int size, int sx, int sy, int ex, int ey)
{
    memset(visited, false, sizeof(visited));

    int dist = MAX;
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});
    visited[sx][sy] = true;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        // 도착
        if (x == ex && y == ey)
        {
            dist = cnt;
            break;
        }
        visited[x][y] = true;

        // 다음 좌표
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            { // 범위 안에서
                if (size >= map[nx][ny] && !visited[nx][ny])
                {                                // size보다 작거나 같으면 움직일 수 있다.
                    q.push({{nx, ny}, cnt + 1}); // 이동거리는 1
                }
            }
        }
    }

    return dist;
}

// cnt - 움직인 거리, eat먹은 횟수, size = 상어 크기, x,y 상어 좌표
void sharkMove(int cnt, int eat, int size, int x, int y)
{
    int nx, ny;
    int dist = MAX;

    // 다음에 갈 수 있는 장소 탐색 O(N^2 + dist계산)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] != 0 && map[i][j] < size)
            {                                            // 먹을 수 있다.
                int nowDist = getDist(size, x, y, i, j); // 어떻게 줄이지?

                if (nowDist < dist) // 거리가 같으면 i랑 j가 작은 쪽이 다음 타겟이 된다.
                {
                    nx = i;
                    ny = j;
                    dist = nowDist;
                }
            }
        }
    }

    // 갱신이 되지 않았으면 끝/
    if (dist == MAX)
    {
        cout << cnt;
        return;
    }

    cout << nx << " " << ny << " " << dist << '\n';

    map[nx][ny] = 0; // 상어가 먹었다!
    eat++;
    if (eat == size)
    { // 상어 레벨업~!
        size++;
        eat = 0;
    }
    sharkMove(cnt + dist, eat, size, nx, ny);
}

void solve()
{
    cin >> N;

    int sharkX = -1;
    int sharkY = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 9)
            {
                sharkX = i;
                sharkY = j;
                map[i][j] = 0;
            }
        }
    }

    sharkMove(0, 0, 2, sharkX, sharkY);
}

int main()
{
    fastIO();
    solve();
}