#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct taxi
{
    int personX;
    int personY;
    int destX;
    int destY;
};

struct order
{
    int dist;
    int index;
    int personX;
    int personY;
};

int map[21][21];
bool visited[21][21][401][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(const order &a, const order &b)
{
    if (a.dist == b.dist)
    {
        if (a.personX == b.personX)
        {
            return a.personY < b.personY;
        }
        return a.personX < b.personX;
    }
    return a.dist < b.dist;
}

int getDist(int a, int b, int c, int d, int N)
{
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, int>> q;
    q.push({{a, b}, 0});
    visited[a][b][0][0] = true;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (x == c and y == d)
            return cnt;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 or nx > N or ny < 1 or ny > N)
                continue;
            if (visited[nx][ny][0][0] or map[nx][ny])
                continue;

            visited[nx][ny][0][0] = true;
            q.push({{nx, ny}, cnt + 1});
        }
    }
    return -1;
}

int bfs(int N, int startX, int startY, int foil, vector<taxi> list, vector<order> orderList)
{
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, int>> q;
    q.push({{startX, startY}, foil});

    int turn = 0;
    int index = orderList[turn].index;
    int nextPersonX = list[index].personX;
    int nextPersonY = list[index].personY;
    int nextDestX = list[index].destX;
    int nextDestY = list[index].destY;
    int cnt = 1;
    bool flag = false;

    visited[startX][startY][turn][flag] = true;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int foil = q.front().second;
        q.pop();

        cout << "---------------------\n";
        cout << "DEST : " << nextPersonX << " " << nextPersonY << " " << nextDestX << " " << nextDestY << '\n';
        cout << x << " " << y << " " << foil << " " << flag << " " << index << '\n';
        cout << "---------------------\n";
        if (!flag)
        {
            if (x == nextPersonX and y == nextPersonY)
            {
                flag = true;
            }
        }
        else
        {
            if (x == nextDestX and y == nextPersonY)
            {
                cnt++;
                if (cnt == list.size())
                    return foil;
                flag = false;
                foil += (abs(nextPersonX - nextDestX) + abs(nextPersonY - nextDestY)) * 2;
                index = orderList[++turn].index;
                nextDestX = list[index].destX;
                nextDestY = list[index].destY;
                nextPersonX = list[index].personX;
                nextPersonY = list[index].personY;
            }
        }

        if (foil == 0)
            return -1; // fail finish
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 or nx > N or ny < 1 or ny > N)
                continue;
            if (visited[nx][ny][turn][flag] or map[nx][ny])
                continue;

            visited[nx][ny][turn][flag] = true;
            q.push({{nx, ny}, foil - 1});
        }
    }
    return -1;
}

void solve()
{
    int N, M, foil, startX, startY;
    cin >> N >> M >> foil;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];
    cin >> startX >> startY;

    vector<taxi> list(M);
    vector<order> orderList(M);
    for (int i = 0; i < M; i++)
    {
        cin >> list[i].personX >> list[i].personY >> list[i].destX >> list[i].destY;
        orderList[i].dist = abs(list[i].personX - list[i].destX) + abs(list[i].personY - list[i].destY);
        orderList[i].index = i;
        orderList[i].personX = list[i].personX;
        orderList[i].personY = list[i].personY;
    }
    vector<pair<int, int>> tempOrder;
    for (int i = 0; i < list.size(); i++)
    {
        tempOrder.push_back({getDist(list[i].destX, list[i].destY, list[i].personX, list[i].personY, N), i});
    }
    sort(tempOrder.begin(), tempOrder.end());
    for (int i = 0; i < tempOrder.size(); i++)
    {
        cout << tempOrder[i].first << '\n';
        orderList[i].index = tempOrder[i].second;
    }
    sort(orderList.begin(), orderList.end(), cmp);

    int ans = bfs(N, startX, startY, foil, list, orderList);
    cout << ans;
}

int main()
{
    fastIO();
    solve();
}
