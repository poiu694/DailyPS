#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct people
{
  int x;
  int y;
  int lCnt;
  int rCnt;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[1001][1001];
bool visited[1001][1001];

void fastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int bfs(int N, int M, int L, int R, int startX, int startY)
{
  memset(visited, false, sizeof(visited));
  queue<people> q;
  q.push({startX, startY, L, R});
  visited[startX][startY] = true;

  int ret = 1;
  while (!q.empty())
  {
    int x = q.front().x;
    int y = q.front().y;
    int l = q.front().lCnt;
    int r = q.front().rCnt;
    q.pop();

    // Top & Down
    for (int i : {0, 2})
    {
      int nx = x;
      int ny = y;

      while (nx >= 0 and nx < N)
      {
        nx += dx[i];

        if (nx < 0 or ny < 0 or nx >= N or ny >= M)
          continue;
        if (board[nx][ny] == 1)
          break;
        if (visited[nx][ny])
          continue;

        visited[nx][ny] = true;
        ret++;
        q.push({nx, ny, l, r});
      }
    }

    // Left & Right
    for (int i : {1, 3})
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 or ny < 0 or nx >= N or ny >= M)
        continue;
      if (board[nx][ny] == 1 or visited[nx][ny])
        continue;
      if (l == 0 and i == 3)
        continue;
      if (r == 0 and i == 1)
        continue;

      visited[nx][ny] = true;
      ret++;
      if (i == 1)
        q.push({nx, ny, l, r - 1});
      else
        q.push({nx, ny, l - 1, r});
    }
  }

  return ret;
}

void solve()
{
  int N, M, L, R, startX, startY;

  string str;
  cin >> N >> M >> L >> R;
  for (int i = 0; i < N; i++)
  {
    cin >> str;

    for (int j = 0; j < M; j++)
    {
      board[i][j] = str[j] - '0';

      if (board[i][j] == 2)
      {
        startX = i;
        startY = j;
      }
    }
  }

  cout << bfs(N, M, L, R, startX, startY);
}

int main()
{
  fastIO();
  solve();
}
