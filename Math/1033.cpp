#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

vector<pair<int, pair<int, int>>> graph[11];
bool visited[11];
pair<int, int> rate[11];

void fastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

long gcd(long a, long b)
{
  long r;
  while (b != 0)
  {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void bfs(int node)
{
  queue<int> qu;

  qu.push(node);
  visited[node] = true;
  rate[node] = {1, 1};

  int p, q;
  while (!qu.empty())
  {
    int nowNode = qu.front();
    qu.pop();

    for (auto next : graph[nowNode])
    {
      int nextNode = next.first;
      tie(p, q) = next.second;

      if (visited[nextNode])
        continue;

      rate[nextNode] = {q * rate[nowNode].first, p * rate[nowNode].second};
      long g = gcd(rate[nextNode].first, rate[nextNode].second);
      rate[nextNode] = {rate[nextNode].first / g, rate[nextNode].second / g};

      visited[nextNode] = true;
      qu.push(nextNode);
    }
  }
}

void solve()
{
  int N;
  cin >> N;

  vector<int> r(N, 1);
  int a, b, p, q;
  for (int i = 0; i <= N; i++)
    rate[i] = {-1, -1};

  for (int i = 0; i < N - 1; i++)
  {
    cin >> a >> b >> p >> q;
    graph[a].push_back({b, {p, q}});
    graph[b].push_back({a, {q, p}});
  }

  memset(visited, false, sizeof(visited));
  bfs(0);

  long g = 1;
  long lcm = 1;
  for (int i = 0; i < N; i++)
  {
    lcm = lcm * rate[i].second / gcd(lcm, rate[i].second);
  }

  for (int i = 0; i < N; i++)
  {
    cout << rate[i].first * lcm / rate[i].second << " ";
  }
}

int main()
{
  fastIO();
  solve();
}
