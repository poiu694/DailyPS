#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

void fastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve()
{
  int N, K, temp;
  cin >> N >> K;

  priority_queue<int> pq;
  for (int i = 0; i < N; i++)
  {
    cin >> temp;
    pq.push(-temp);
  }

  int target = 1;
  while (!pq.empty())
  {
    int top = -pq.top();
    pq.pop();

    if (top == target)
      target++;
    else if (top < target)
      pq.push(-(top + K));
    else
      break;
  }

  if (target == N + 1)
    cout << 1;
  else
    cout << 0;
}

int main()
{
  fastIO();
  solve();
}
