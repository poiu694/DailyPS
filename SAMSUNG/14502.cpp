#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int N, M;
int map[10][10];
int tempMap[10][10];
queue<pair<int, int>> q;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void copyMap()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tempMap[i][j] = map[i][j];

            if (map[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }
}

void bfs()
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        tempMap[x][y] = 2;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            { // Out Of Bounds
                continue;
            }

            if (tempMap[nx][ny] == 0)
            { // 1 과 2 무시
                q.push({nx, ny});
            }
        }
    }
}

int safeSpot()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cnt += (tempMap[i][j] == 0);
        }
    }
    return cnt;
}

void solve()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    int answer = -1;
    for (int brute = 0; brute < 262114; brute++)
    {                     // 3Locate BF, (64 * 64 * 64)
        copyMap();        // O(64)
        int past = -1;    // 좌표가 겹치지 않게 해주는 변수
        bool flag = true; // 중복되지 않는 3개의 벽을 세웠는가 ?
        int temp = brute; // 64진법 변환용 변수

        for (int i = 0; i < 3; i++)
        {                            // 3 WALL
            int digit64 = temp % 64; // 64진법 변환
            temp /= 64;
            if (past == digit64)
            {
                flag = false;
                break;
            }
            past = digit64;

            int x = digit64 / 8; // 0~63을 0,0 ~ 7,7로 치환
            int y = digit64 % 8;
            if (tempMap[x][y] != 0)
            { // 한개라도 0이 아니면 3개의 벽 x
                flag = false;
                break;
            }
            tempMap[x][y] = 1;
        }
        if (flag)
        {
            bfs();
            answer = max(answer, safeSpot());
        }
    }
    cout << answer;
}

int main()
{
    fastIO();
    solve();
}