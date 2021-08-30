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

  vector<int> list(N);
  for (int i = 0; i < N; i++)
    cin >> list[i];

  bool flag = false;
  do
  {
    if (flag)
    {
      for (int i = 0; i < N; i++)
        cout << list[i] << " ";
      return;
    }
    else
      flag = true;
  } while (next_permutation(list.begin(), list.end()));

  cout << -1;
}

int main()
{
  fastIO();
  solve();
}
