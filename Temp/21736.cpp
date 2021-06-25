#include <iostream>

using namespace std;

int N, M, sX, sY;
int cnt = 0;
char map[601][601];
bool visited[601][601];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int x, int y)
{
    visited[x][y] = true;
    if (map[x][y] == 'P')
    {
        cnt++;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < M)
        {
            if (!visited[nx][ny] && map[nx][ny] != 'X')
            {
                dfs(nx, ny);
            }
        }
    }
}

void solve()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'I')
            {
                sX = i;
                sY = j;
            }
        }
    }

    dfs(sX, sY);
    if (cnt != 0)
    {
        cout << cnt;
    }
    else
    {
        cout << "TT";
    }
}

int main()
{
    fastIO();
    solve();
}