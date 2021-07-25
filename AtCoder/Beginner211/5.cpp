#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int N, M;
char map[10][10], tempMap[10][10];
bool visited[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void bfs(int i, int j)
{
    q.push({i, j});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 or nx >= N or ny < 0 or ny >= M)
                continue;
            if (visited[nx][ny])
                continue;

            if (tempMap[nx][ny] == '@')
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void solve()
{
    cin >> N >> M;
    string temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        for (int j = 0; j < N; j++)
            map[i][j] = temp[j];
    }
    long long answer = 0;
    long long repeat = 1;
    for (int i = 0; i < M; i++)
        repeat *= 64;
    cout << repeat << " ";
    for (long long brute = 0; brute < repeat; brute++)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                tempMap[i][j] = map[i][j];

        long long temp = brute;
        bool flag = true;

        for (int i = 0; i < M; i++)
        {
            int digit64 = temp % 64;
            temp /= 64;

            int x = digit64 / 8;
            int y = digit64 % 8;
            if (x >= N or y >= N)
            {
                flag = false;
                break;
            }
            if (tempMap[x][y] == '#' or tempMap[x][y] == '@')
            {
                flag = false;
                break;
            }

            tempMap[x][y] = '@';
        }

        if (flag)
        {
            memset(visited, false, sizeof(visited));
            int cnt = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (tempMap[i][j] == '@')
                    {
                        bfs(i, j);
                        cnt++;
                    }
                }
            }

            if (cnt == 1)
                answer++;
        }
    }
    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
