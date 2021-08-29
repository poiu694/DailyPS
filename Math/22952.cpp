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
  int N;
  cin >> N;

  int temp = 1;
  for (int i = 1; i <= N; i++)
  {
    if (i % 2 != 0)
      cout << N - (temp - 1) << " ";
    else
      cout << temp++ << " ";
  }
}

int main()
{
  fastIO();
  solve();
}
