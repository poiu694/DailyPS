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
  int N;
  cin >> N;

  vector<pair<string, string>> list(N);
  string a, b;
  for (int i = 0; i < N; i++)
  {
    cin >> a >> b;
    list[i] = {a, b};
  }

  sort(list.begin(), list.end());
  a = list[0].first;
  b = list[0].second;
  for (int i = 1; i < list.size(); i++)
  {
    if (a == list[i].first and b == list[i].second)
    {
      cout << "Yes";
      return;
    }
    else
    {
      a = list[i].first;
      b = list[i].second;
    }
  }

  cout << "No";
}

int main()
{
  fastIO();
  solve();
}
