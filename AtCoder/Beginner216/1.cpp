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
  string target;
  cin >> target;

  string x = target.substr(0, target.find("."));
  char y = target[target.find(".") + 1];
  if (y <= '2')
    y = '-';
  else if (y <= '6')
  {
    cout << x;
    return;
  }
  else
    y = '+';
  cout << x << y;
}

int main()
{
  fastIO();
  solve();
}
