#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <limits.h>

using namespace std;

char map[1501][1501];
bool visited[1501][1501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
pair<int, int> finalDuck;
queue<pair<int, int>> duck;
queue<pair<int, int>> nextDuck;
queue<pair<int, int>> waters;
queue<pair<int, int>> nextWaters;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void updateMap(int R, int C)
{
    while (!waters.empty())
    {
        int x = waters.front().first;
        int y = waters.front().second;
        waters.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;
            if (map[nx][ny] == 'X')
            {
                map[nx][ny] = '.';
                nextWaters.push({nx, ny});
            }
        }
    }
}

bool bfs(int R, int C)
{
    while (!duck.empty())
    {
        int x = duck.front().first;
        int y = duck.front().second;
        duck.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (visited[nx][ny])
                continue;

            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;

            if (map[nx][ny] == 'X')
            {
                visited[nx][ny] = true;
                nextDuck.push({nx, ny});
                continue;
            }

            if (nx == finalDuck.first && ny == finalDuck.second)
            {
                return true;
            }
            else
            {
                visited[nx][ny] = true;
                duck.push({nx, ny});
            }
        }
    }
    return false;
}

void solve()
{
    memset(visited, false, sizeof(visited));

    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'L')
            {
                if (duck.size() == 1)
                {
                    finalDuck = {i, j};
                    waters.push({i, j});
                    continue;
                }
                else
                {
                    duck.push({i, j});
                }
            }
            if (map[i][j] != 'X')
            {
                waters.push({i, j});
            }
        }
    }

    int day = 0;
    while (true)
    {
        if (bfs(R, C))
        {
            break;
        }
        else
        {
            day++;
            updateMap(R, C);

            while (!nextWaters.empty())
            {
                waters.push(nextWaters.front());
                nextWaters.pop();
            }

            while (!nextDuck.empty())
            {
                duck.push(nextDuck.front());
                nextDuck.pop();
            }
        }
    }

    cout << day;
}

int main()
{
    fastIO();
    solve();
}
