#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

vector<int> list[401];
int favoriteMap[21][21];
int map[21][21];
int zeroMap[21][21];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void makeFavoriteMap(int N, int nowPerson)
{ // O(4 * N^2)
    memset(favoriteMap, 0, sizeof(favoriteMap));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int favoritePerson : list[nowPerson])
            {
                if (favoritePerson == map[i][j])
                {
                    if (i - 1 >= 0 && map[i - 1][j] == 0)
                        favoriteMap[i - 1][j]++;
                    if (j - 1 >= 0 && map[i][j - 1] == 0)
                        favoriteMap[i][j - 1]++;
                    if (i + 1 < N && map[i + 1][j] == 0)
                        favoriteMap[i + 1][j]++;
                    if (j + 1 < N && map[i][j + 1] == 0)
                        favoriteMap[i][j + 1]++;
                }
            }
        }
    }
}

vector<pair<int, int> > findFavLocate(int N)
{ // O(N^2)
    vector<pair<int, int> > ret;

    int maxFav = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (maxFav < favoriteMap[i][j])
            {
                maxFav = favoriteMap[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (maxFav == favoriteMap[i][j] && map[i][j] == 0)
            {
                ret.push_back({i, j});
            }
        }
    }

    return ret;
}

void updateZeroMap(int N)
{ // O(N^2)
    memset(zeroMap, 0, sizeof(zeroMap));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 0)
            {
                if (i - 1 >= 0)
                    zeroMap[i - 1][j]++;
                if (j - 1 >= 0)
                    zeroMap[i][j - 1]++;
                if (i + 1 < N)
                    zeroMap[i + 1][j]++;
                if (j + 1 < N)
                    zeroMap[i][j + 1]++;
            }
        }
    }
}

void solve()
{
    int N;
    cin >> N;

    queue<int> orderList;
    for (int i = 0; i < N * N; i++)
    {
        int now;
        cin >> now;

        orderList.push(now);
        int temp;
        for (int j = 0; j < 4; j++)
        {
            cin >> temp;
            list[now].push_back(temp);
        }
    }
    while (!orderList.empty())
    {
        int nowPerson = orderList.front();
        orderList.pop();

        makeFavoriteMap(N, nowPerson);
        vector<pair<int, int> > locateList = findFavLocate(N);
        updateZeroMap(N);

        int seatX = -1;
        int seatY = -1;
        int zeroCnt = -1;
        for (auto locate : locateList)
        {
            if (zeroCnt < zeroMap[locate.first][locate.second])
            {
                zeroCnt = zeroMap[locate.first][locate.second];
                seatX = locate.first;
                seatY = locate.second;
            }
        }
        map[seatX][seatY] = nowPerson;
    }

    memset(favoriteMap, 0, sizeof(favoriteMap));
    int sum = 0;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            int seatPerson = map[x][y];

            for (int favPerson : list[seatPerson])
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;

                    if (favPerson == map[nx][ny])
                    {
                        favoriteMap[x][y]++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (favoriteMap[i][j] == 1)
            {
                sum += 1;
            }
            else if (favoriteMap[i][j] == 2)
            {
                sum += 10;
            }
            else if (favoriteMap[i][j] == 3)
            {
                sum += 100;
            }
            else if (favoriteMap[i][j] == 4)
            {
                sum += 1000;
            }
        }
    }
    cout << sum;
}

int main()
{
    fastIO();
    solve();
}
