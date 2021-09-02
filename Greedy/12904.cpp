#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

void fastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve()
{
  string start, target;
  cin >> start >> target;

  while (target.size() != start.size())
  {
    if (target.back() == 'A')
    {
      target.pop_back();
    }
    else
    {
      target.pop_back();
      reverse(target.begin(), target.end());
    }
  }

  if (target == start)
    cout << 1;
  else
    cout << 0;
}

int main()
{
  fastIO();
  solve();
}
