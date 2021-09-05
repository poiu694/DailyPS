#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct User
{
  int x;
  int y;
  int time;
  int k;
  int move;
};

int board[1001][1001];
bool visited[1001][1001][2][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int bfs(int N, int M, int K)
{
  memset(visited, false, sizeof(visited));

  queue<User> q;
  q.push({0, 0, 0, K, 1}); // time 0 : 낮, time 1 : 밤
  visited[0][0][1][K] = true;
  while (!q.empty())
  {
    int x = q.front().x;
    int y = q.front().y;
    int time = q.front().time;
    int k = q.front().k;
    int move = q.front().move;
    q.pop();

    if (x == N - 1 and y == M - 1)
      return move;

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 or ny < 0 or nx >= N or ny >= M)
        continue;
      // 낮
      if (time == 0)
      {
        // 벽이 아닌 경우
        if (board[nx][ny] == 0)
        {
          if (visited[nx][ny][(time + 1) % 2][k])
            continue;
          visited[nx][ny][(time + 1) % 2][k] = true;
          q.push({nx, ny, (time + 1) % 2, k, move + 1});
        }
        // 벽인 경우
        else
        {
          if (k == 0)
            continue;
          if (visited[nx][ny][(time + 1) % 2][k - 1])
            continue;
          visited[nx][ny][(time + 1) % 2][k - 1] = true;
          q.push({nx, ny, (time + 1) % 2, k - 1, move + 1});
        }
      }
      // 밤
      else
      {
        if (board[nx][ny] == 1 or visited[nx][ny][(time + 1) % 2][k])
          continue;
        visited[nx][ny][(time + 1) % 2][k] = true;
        q.push({nx, ny, (time + 1) % 2, k, move + 1});
      }
    }

    if (visited[x][y][(time + 1) % 2][k])
      continue;
    visited[x][y][(time + 1) % 2][k] = true;
    q.push({x, y, (time + 1) % 2, k, move + 1});
  }

  return -1;
}

void solve()
{
  int N, M, K;
  cin >> N >> M >> K;

  string s;
  for (int i = 0; i < N; i++)
  {
    cin >> s;
    for (int j = 0; j < M; j++)
      board[i][j] = s[j] - '0';
  }

  cout << bfs(N, M, K);
}

int main()
{
  fastIO();
  solve();
}
