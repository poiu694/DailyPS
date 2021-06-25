#include <iostream>
#include <vector>

using namespace std;

int N, M;
int temp[10][10];
int map[10][10];
vector<pair<int, int>> cctv;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // N - E - S - W

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
            temp[i][j] = map[i][j];
        }
    }
}

void updateMap(int x, int y, int dir)
{
    dir = dir % 4;
    while (true)
    {
        x = x + dx[dir];
        y = y + dy[dir];

        if (x < 0 || y < 0 || x >= N || y >= M || temp[x][y] == 6)
        {
            return;
        }

        if (temp[x][y] != 0)
        { // cctv면 뚫고 지나가기
            continue;
        }

        temp[x][y] = 10;
    }
}

int findBlindSpot()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp[i][j] == 0)
            {
                cnt++;
            }
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

            if (map[i][j] != 0 && map[i][j] != 6)
            {
                cctv.push_back({i, j});
            }
        }
    }

    int answer = 100; // 100 > 64(8*8)
    // CCTV < 8
    // 4^CCTV(CCTV DIRECTION)
    for (int brute = 0; brute < (1 << (2 * cctv.size())); brute++)
    {
        copyMap();

        int temp = brute;
        for (int i = 0; i < cctv.size(); i++)
        {
            int dir = temp % 4;
            temp /= 4;

            int x = cctv[i].first;
            int y = cctv[i].second;
            if (map[x][y] == 1)
            {
                updateMap(x, y, dir);
            }
            else if (map[x][y] == 2)
            {
                updateMap(x, y, dir);
                updateMap(x, y, dir + 2);
            }
            else if (map[x][y] == 3)
            {
                updateMap(x, y, dir);
                updateMap(x, y, dir + 1);
            }
            else if (map[x][y] == 4)
            {
                updateMap(x, y, dir);
                updateMap(x, y, dir + 1);
                updateMap(x, y, dir + 2);
            }
            else if (map[x][y] == 5)
            {
                updateMap(x, y, dir);
                updateMap(x, y, dir + 1);
                updateMap(x, y, dir + 2);
                updateMap(x, y, dir + 3);
            }
        }

        answer = min(answer, findBlindSpot());
    }

    cout << answer;
}

int main()
{
    fastIO();
    solve();
}