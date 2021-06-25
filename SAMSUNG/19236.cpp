#include <iostream>

using namespace std;

pair<int, int> map[5][5];
pair<int, int> tempMap[5][5];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int ans = -1;

struct shark
{
    int x;
    int y;
    int size;
    int dir;
};

struct compare
{
    bool operator()(const shark &s1, const shark &s2)
    {
        return s1.size > s2.size;
    }
};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

pair<int, int> findNextFish(int target)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map[i][j].first == target)
            {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

int lastFishSize()
{
    int max = -1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (max < map[i][j].first)
            {
                max = map[i][j].first;
            }
        }
    }
    return max;
}

void moveFishMap()
{
    int target = 1;
    int lastFish = lastFishSize();
    while (true)
    {
        auto fish = findNextFish(target);
        if (fish.first == -1 && fish.second == -1)
        {
            if (target != lastFish + 1)
            {
                target++;
                continue;
            }
            else
            {
                return;
            }
        }

        int x = fish.first;
        int y = fish.second;
        int size = map[x][y].first;
        int dir = map[x][y].second;

        int nx, ny;
        while (true)
        {
            nx = x + dx[dir - 1];
            ny = y + dy[dir - 1];

            if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
            { // OOB
                if (map[nx][ny].first != -1)
                {
                    break;
                }
            }

            dir = dir + 1;
            dir = (dir > 8) ? 1 : dir;
        }

        // swap (x,y) < - > (nx, ny)
        pair<int, int> temp = map[nx][ny];
        map[nx][ny] = {size, dir};
        map[x][y] = temp;
        target++;
    }
}

void copyToTempMap()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tempMap[i][j] = map[i][j];
        }
    }
}

void copyToMap()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            map[i][j] = tempMap[i][j];
        }
    }
}

void dfs(int sharkX, int sharkY, int sharkDir, int sum)
{
    if (sum > ans)
    {
        ans = sum;
    }
    moveFishMap();
    cout << sum << '\n';
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << map[i][j].first << ' ';
        }
        cout << endl;
    }

    // Shark Move
    for (int i = 1; i <= 3; i++)
    {
        copyToTempMap();
        int nx = sharkX + i * dx[sharkDir - 1];
        int ny = sharkY + i * dy[sharkDir - 1];
        int nsize = map[nx][ny].first;
        int ndir = map[nx][ny].second;

        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
        {
            continue;
        }

        if (tempMap[nx][ny].first == 0)
        { // ?
            continue;
        }

        tempMap[nx][ny] = tempMap[sharkX][sharkY];
        tempMap[sharkX][sharkY] = {-1, -1};
        dfs(nx, ny, ndir, sum + nsize);
    }
}

void solve()
{
    pair<int, int> sharkLocate;
    int sharkDir;
    int now = 0;

    int fish, dir;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> fish >> dir;
            if (i == 0 && j == 0)
            {
                sharkLocate = {0, 0};
                sharkDir = dir;
                now += fish;
                map[0][0] = {-1, 0};
                continue;
            }
            map[i][j] = {fish, dir};
        }
    }

    dfs(sharkLocate.first, sharkLocate.second, sharkDir, now);

    cout << ans;
}

int main()
{
    fastIO();
    solve();
}
